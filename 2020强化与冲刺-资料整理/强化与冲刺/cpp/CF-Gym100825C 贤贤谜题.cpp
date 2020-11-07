#include<bits/stdc++.h>
using namespace std;
int n, m, t, ans, x[10], y[10], ux[10][10], uy[10][10];// 和数独一样表示同行 同列 
long long power[11];
char op;
void dfsadd(int now, int sum) {
	// now 现在已经填了几个格子
	// sum 当前填过的数字和是多少 
	// t 是目标的和 
    if(sum >= t || (t-sum) > (m-now)*n || (t-sum) < (m-now))    return;
    //  (t-sum) > (m-now)*n 如果剩下来的格子全填最大的数字n，和还不够，也不用搜索了
	//  (t-sum) < (m-now)*1 如果剩下来的格子全填最小的数字1，和还超过，也不用搜索了 
    if(now == m-1) {
    	// 我已经填了m-1个格子， 当前在填最后一个格子 
        sum = t - sum;
        if(!ux[ x[now] ][sum] && !uy[ y[now] ][sum])    ans++;
        return;
    }
    for(int i=1;i<=n;i++) // 枚举当前格子填什么数字（i） 
    {
        if(ux[ x[now] ][i] || uy[ y[now] ][i])  continue;
        ux[ x[now] ][i] = uy[ y[now] ][i] = 1;
        dfsadd(now+1, sum+i);
        ux[ x[now] ][i] = uy[ y[now] ][i] = 0;
    }
}
void dfsmul(int now, int mul) {
	// now 已经填了now个格子 mul 是已有的乘积 
    if(mul > t || t%mul || t/mul > power[m-now])    return;
    // 如果全填最大的数字，它的积不够，不用搜索，全填最小的，也不用搜索 
    if(now == m-1) {
    	//如果是最后一个格子，就直接一步到位，判断能不能填 
        mul = t / mul;
        if(!ux[ x[now] ][mul] && !uy[ y[now] ][mul])    ans++;
        return;
    }
    for(int i=1;i<=n;i++) //搜索枚举填什么数字（i） 
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
	// 读入数据，最大可填数字 ，格子数，操作的结果，运算符 
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
