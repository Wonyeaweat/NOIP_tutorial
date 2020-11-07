#include<bits/stdc++.h>
using namespace std;
int n,m,dis[100001],head[100001],cnt,ss,st,t[100001],ans;
bool s[100001],inq[100001];
struct b
{
	int to,nxt,w;
}e[300001];
inline void add(int u,int v,int ff){cnt++,e[cnt].nxt=head[u],e[cnt].to=v,e[cnt].w=ff,head[u]=cnt;}
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}
inline void dij(int x)
{
	for(register int i=1;i<=n;i++)dis[i]=2147483640;
	dis[x]=0;
	inq[x]=true;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int f=q.top().second;
		q.pop();
		inq[f]=false;
		for(register int i=head[f];i;i=e[i].nxt)
		{
			if(dis[f]+e[i].w<dis[e[i].to])
			{
				dis[e[i].to]=dis[f]+e[i].w;
				if(inq[e[i].to]==false)
				{
					inq[e[i].to]=true;
					q.push(make_pair(-dis[e[i].to],e[i].to));
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("T1.in","r",stdin);
	freopen("T1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++)
	{
		int u,v,ff;
		scanf("%d%d%d",&u,&v,&ff);
		add(u,v,ff);
		add(v,u,ff);
	}
	scanf("%d%d",&ss,&st);
	for(register int i=1;i<=ss;i++)
	{
		int x;
		scanf("%d",&x);
		s[x]=true;
	}
	for(register int i=1;i<=st;i++)
	{
		scanf("%d",&t[i]);
		dij(t[i]);
		int mn=2147483647;
		for(register int j=1;j<=n;j++)
			if(dis[j]<mn&&(s[j]==true))mn=dis[j];
		ans+=mn;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
