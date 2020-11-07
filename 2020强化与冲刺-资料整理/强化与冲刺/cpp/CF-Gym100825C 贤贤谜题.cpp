#include<bits/stdc++.h>
using namespace std;
int n, m, t, ans, x[10], y[10], ux[10][10], uy[10][10];// ������һ����ʾͬ�� ͬ�� 
long long power[11];
char op;
void dfsadd(int now, int sum) {
	// now �����Ѿ����˼�������
	// sum ��ǰ��������ֺ��Ƕ��� 
	// t ��Ŀ��ĺ� 
    if(sum >= t || (t-sum) > (m-now)*n || (t-sum) < (m-now))    return;
    //  (t-sum) > (m-now)*n ���ʣ�����ĸ���ȫ����������n���ͻ�������Ҳ����������
	//  (t-sum) < (m-now)*1 ���ʣ�����ĸ���ȫ����С������1���ͻ�������Ҳ���������� 
    if(now == m-1) {
    	// ���Ѿ�����m-1�����ӣ� ��ǰ�������һ������ 
        sum = t - sum;
        if(!ux[ x[now] ][sum] && !uy[ y[now] ][sum])    ans++;
        return;
    }
    for(int i=1;i<=n;i++) // ö�ٵ�ǰ������ʲô���֣�i�� 
    {
        if(ux[ x[now] ][i] || uy[ y[now] ][i])  continue;
        ux[ x[now] ][i] = uy[ y[now] ][i] = 1;
        dfsadd(now+1, sum+i);
        ux[ x[now] ][i] = uy[ y[now] ][i] = 0;
    }
}
void dfsmul(int now, int mul) {
	// now �Ѿ�����now������ mul �����еĳ˻� 
    if(mul > t || t%mul || t/mul > power[m-now])    return;
    // ���ȫ���������֣����Ļ�����������������ȫ����С�ģ�Ҳ�������� 
    if(now == m-1) {
    	//��������һ�����ӣ���ֱ��һ����λ���ж��ܲ����� 
        mul = t / mul;
        if(!ux[ x[now] ][mul] && !uy[ y[now] ][mul])    ans++;
        return;
    }
    for(int i=1;i<=n;i++) //����ö����ʲô���֣�i�� 
    {
        if(ux[ x[now] ][i] || uy[ y[now] ][i])  continue;
        ux[ x[now] ][i] = uy[ y[now] ][i] = 1;
        dfsmul(now+1, mul*i);
        ux[ x[now] ][i] = uy[ y[now] ][i] = 0;
    }
}
int main()
{
    scanf("%d %d %d %c", &n, &m, &t, &op);
	// �������ݣ����������� ���������������Ľ��������� 
    for(int i=0;i<m;i++)
        scanf("%d %d", &x[i], &y[i]);
    if(op == '-') {
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=n;j++)
            	if(i==j)    continue;
            		else if(abs(i-j) == t)  
						ans++;
    } else if(op == '/') {
        for(int i=1;i<=n;i++)
        	for(int j=i+1;j<=n;j++)
            	if(j%i==0 && j/i==t)    
					ans+=2;
    } else if(op == '+') dfsadd(0, 0);    
	else {
        power[0] = 1;
        for(int i=1;i<=m;i++)
            power[i] = power[i-1] * n;
        dfsmul(0, 1);
    }
    printf("%d\n", ans);
}
