#include<cstdio>
#include<cstring>
#define mod 1000007
int max(int x,int y){return x>y?x:y;}
int f[101][101];//f[i][j]ָ�ڵ�i�������ܹ���j������Ž�
int main()
{
	freopen("cyberpunk.in","r",stdin);
    freopen("cyberpunk.out","w",stdout);
    int n,m,t;
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    for(int i=0;i<=n;i++)
        f[i][0]=1;
    for(int i=1;i<=n;i++)//ö�ٵ���i�軨
    {
        scanf("%d",&t);
        for(int j=0;j<=t;j++)//��i�軨װj��
            for(int k=0;k<=m-j;k++)//���Ѿ�װk��ת�ƹ���
            {
                if(j==0&&k==0)
                    continue;
                f[i][j+k]+=f[i-1][k];
                f[i][j+k]%=mod;
            }
    }
    printf("%d\n",f[n][m]%mod);
    return 0;
}

