#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=1e5+10,M=6e5+10; 
int n,m;
struct edge{
	int nxt,go,val;
}e[M*2];
int head[N],cnt;
void add(int u,int v,int w){e[++cnt]=(edge){head[u],v,w},head[u]=cnt;}
int p,q;
int s[N],t[N];

int ans1=2e9;
bool used[N];
void dfs(int u,int sum)
{
	if(u==t[1])
	{
		ans1=min(ans1,sum);
		return ;
	}
	used[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].go;
		if(!used[v])
			dfs(v,sum+e[i].val);
	}
	used[u]=0;
}

int ans;
struct data{
	int num,sum;
	bool operator <(const data a)const
	{
		return sum>a.sum;
	}
};
bool vis[N];
int dis[N];
void dijkstra(int s)
{
	priority_queue<data> q;
	q.push((data){s,0});
	for(int i=1;i<=n;i++)
		vis[i]=0,dis[i]=0x3f3f3f3f;
	dis[s]=0;
	while(!q.empty())
	{
		data u=q.top();
		q.pop();
		if(vis[u.num])
			continue;
		vis[u.num]=1;
		int a=u.num,d=u.sum;
		for(int i=head[a];i;i=e[i].nxt)
		{
			int v=e[i].go;
			if(dis[v]>d+e[i].val)
			{
				dis[v]=d+e[i].val;
				q.push((data){v,dis[v]});
			}
		 } 
	}
}

void read()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w),add(v,u,w); 
	}
	scanf("%d %d",&p,&q);
	for(int i=1;i<=p;i++)
		scanf("%d",s+i);
	for(int i=1;i<=q;i++)
		scanf("%d",t+i);
}
void solve()
{
	if(q==p&&p==1)
		dfs(s[1],0);
	else
	{
		for(int i=1;i<=p;i++)
		{
			dijkstra(s[i]);
			int sum=0x3f3f3f3f;
			for(int j=1;j<=q;j++)
				sum=min(sum,dis[t[j]]);
			ans+=sum;
		}
	}
}
void print()
{
	if(q==p&&p==1)
		printf("%d\n",ans1);
	else
		printf("%d\n",ans);
}
int main()
{
//	freopen("T1.in","r",stdin);
//	freopen("T1.out","w",stdout);
	read();
	solve();
	print();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
