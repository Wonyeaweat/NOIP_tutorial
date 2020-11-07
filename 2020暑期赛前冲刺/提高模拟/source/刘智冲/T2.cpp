#include<cstdio>
typedef long long ll;
const int N=1e3+10,T=1e5+10;
int n,t;
ll a[N][N],qzh[N][N];
struct data{
	int x,y;
}pos[N*N];
#define v1 (x-d+1)
#define v2 (y-d+1)
#define v3 (x+d-1)
#define v4 (y+d-1)
#define v5 (x+d-2)
#define v6 (y+d-2) 
data solve(int x,int y)
{
	if(x>n)
		x=n;
	if(y>n)
		y=n;
	if(x<1)
		x=0;
	if(y<1)
		y=0;
	return (data){x,y};
}
ll sum(int x,int y,int d)
{
	if(d==1)
		return a[x][y];
	ll ret=0;
	data ff=solve(v5,v6);
	ret=qzh[ff.x][ff.y];
	ff=solve(v1,v6);
	ret-=qzh[ff.x][ff.y];
	ff=solve(v5,v2);
	ret-=qzh[ff.x][ff.y];
	ff=solve(v1,v2);
	ret+=qzh[ff.x][ff.y];
	ff=solve(v1,y);
	ret+=a[ff.x][ff.y]; 
	ff=solve(x,v2);
	ret+=a[ff.x][ff.y];
	ff=solve(x,v4);
	ret+=a[ff.x][ff.y];
	ff=solve(v3,y);
	ret+=a[ff.x][ff.y];
	return ret;
}
int main()
{
	freopen("T2.in","r",stdin);
	freopen("T2.out","w",stdout);
	scanf("%d %d",&n,&t);
	ll cnt;
	for(int i=1;i<=n;i++)
	{
		cnt=i;
		for(int j=i;j<=n;j++)
			a[i][j]=cnt,cnt+=1ll*n;
		for(int j=1;j<i;j++)
			a[i][j]=cnt,cnt+=1ll*n;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			pos[a[i][j]]=(data){i,j},qzh[i][j]=qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1]+a[i][j];
	int ddd=1,xx,yy;
	for(int i=1;i<=t;i++)
	{
		int x;
		scanf("%d",&x);
		ddd+=x;
		xx=pos[ddd].x,yy=pos[ddd].y;
		printf("%d\n",sum(xx,yy,x));
	}
	return 0;
}
