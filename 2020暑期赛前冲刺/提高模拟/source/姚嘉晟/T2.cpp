#include<bits/stdc++.h>
using namespace std;
int n,t,a[1001][1001],cnt,f[1001][1001],dx,dy,ds,sx[1000001],sy[1000001];
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
void build()
{
	int i,j,k,li=0,lj=0;
	for(i=1,j=1;i<=n;i++,j++)a[i][j]=++cnt,sx[cnt]=i,sy[cnt]=j,f[li][lj]=a[i][j],li=i,lj=j;
	for(k=1;k<=2*n-2;k++)
	{
		if(k&1)
		{
			i=1,j=(k+1)/2+1;
			while(j<=n)
			{
				a[i][j]=++cnt;
				sx[cnt]=i;
				sy[cnt]=j;
				f[li][lj]=a[i][j];
				li=i,lj=j;
				i++,j++;
			}
		}
		else
		{
			j=1,i=n-(k/2)+1;
			while(i<=n)
			{
				a[i][j]=++cnt;
				sx[cnt]=i;
				sy[cnt]=j;
				f[li][lj]=a[i][j];
				li=i,lj=j;
				i++,j++;
			}
		}
	}
	f[n][n-1]=a[1][1];
	return;
}
int q(int x,int y,int s)
{
	int ans=0;
	for(register int i=max(1,x-s+1);i<=min(n,x+s-1);i++)
	{
		for(register int j=max(1,y-s+1+abs(i-x));j<=min(n,y+s-1-abs(i-x));j++)
		{
			ans+=a[i][j];
		}
	}
	return ans;
}
int main()
{
	freopen("T2.in","r",stdin);
	freopen("T2.out","w",stdout);
	n=read(),t=read();
	build();
	dx=1,dy=1,ds=1;
	for(register int i=1;i<=t;i++)
	{
		int x=read();
		for(register int j=1;j<=x;j++)ds=f[dx][dy],dx=sx[ds],dy=sy[ds];
		cout<<q(dx,dy,x)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
