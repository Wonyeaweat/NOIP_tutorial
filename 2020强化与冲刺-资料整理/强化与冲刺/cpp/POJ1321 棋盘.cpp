#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
char a[10][10];
int n,k,ans=0,visit[10];
void dfs(int cnt,int x,int y){
	/*
	cnt:��ǰ�Ѿ�������cnt������
	x,y:Ŀǰ�ڿ���(x,y)λ�ðڷ����� 
	*/
    if(cnt==k) {
		// ��ǰ�Ѿ�������k�����ӣ�������ĿҪ��
		// ans++,���ؼ��� 
        ans++;
        return ;
    } 
    visit[y]=1;
    // visit���飺visit[i]��ʾ��i���������ӷ���
	// =1��ʾ�����ӣ� =0 ��ʾû������
	// ��ǰλ�� (x,y) ����һö���� 
	
    for(int i=x+1;i<n;i++){
    	// ö�ٽ��������п��԰ڷ����ӵ�λ�ã�����i����j����
		// ��Ϊ�������Ӳ�����ͬһ�У�(x,y) ������ ˵��x�в����ٷ�����
		// ����i��x+1��ʼ ��n-1�н��� ����0��ʼ�� 
        for(int j=0;j<n;j++){
            if(visit[j]==0&&a[i][j]=='#') {
            	// visit[j]==0 ˵����j�л�û������
				// a[i][j]=='#' ˵����λ�����������϶��ǿհ״� 
                dfs(cnt+1,i,j);
                // �������� 
            }
        }
    }
    visit[y]=0;
    // ע�⣺dfsʱ��������������
	// ���е��м��������ָ�һ��ʼ���뵱���״̬
	// ����ȷ���ں���ʱ��������Ϊ���������Ӱ�� 
}
int main(){
    while(~scanf("%d%d",&n,&k)){
    	//�õ���scanf������cin
		// (scanf("%d %d",&n,&k)!=EOF)
        if(n==-1&&k==-1) break;
        for(int i=0;i<n;i++) 
            scanf("%s",a[i]);
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='#') {
                	// ö�ٵ�һ�����Ӱڷŵ�λ�� 
                    memset(visit,0,sizeof(visit));
                    dfs(1,i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
}
