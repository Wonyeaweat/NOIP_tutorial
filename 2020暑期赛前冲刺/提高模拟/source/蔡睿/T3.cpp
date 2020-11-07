#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 100010;
struct edge
{
	int to, nxt, val;
}e[maxn << 1];
int head[maxn], cnt;
int mp[5005][5005];
void add(int x, int y, int z)
{
	e[++cnt].to = y;
	e[cnt].nxt = head[x];
	head[x] = cnt;
	e[cnt].val = z;
}
int par[maxn], dep[maxn], size[maxn], son[maxn], top[maxn];
void dfs(int x)
{
	dep[x] = dep[par[x]] + 1;
	size[x] = 1;
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int t = e[i].to;
		if (t == par[x]) continue;
		par[t] = x;
		dfs(t);
		size[x] += size[t];
		if (!son[x] || size[son[x]] <= size[t]) son[x] = t;
	}
}
void dfs2(int x, int tp)
{
	top[x] = tp;
	if (son[x]) dfs2(son[x], tp);
	for (int i = head[x]; i; i = e[i].nxt)
	{
		int t = e[i].to;
		if (t == par[x] || t == son[x]) continue;
		dfs2(t, t);
	}
}
int lca(int x, int y)
{
	while (dep[x] != dep[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = par[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int main()
{
	freopen("T3.in", "r", stdin);
	freopen("T3.out", "w", stdout);
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z), add(y, x, z);
		mp[x][y] = mp[y][x] = z;
	}
	int lastans = 0;
	while (q--)
	{
		int opt, x, y, z;
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			x = x ^ lastans, y = y ^ lastans, z = z ^ lastans;
			add(x, y, z), add(y, x, z);
			mp[x][y] = mp[y][x] = z;
		}
		else if (opt == 2)
		{
			scanf("%d%d", &x, &y);
			x = x ^ lastans, y = y ^ lastans;
			int ans = 0;
			dfs(x); dfs2(x, x);
			int fk = lca(x, y);
//			do
//			{
//				ans += mp[x][par[x]];
//				x = par[x];
//			}while (par[x] != fk);
			do
			{
				ans += mp[y][par[y]];
				y = par[y];
			}while (par[y] != fk);
			printf("%d\n", lastans = ans);
		}
		else if (opt == 3)
		{
			scanf("%d%d", &x, &y);
			x = x ^ lastans, y = y ^ lastans;
			int ans = -0x3f3f3f3f;
			dfs(x); dfs2(x, x);
			int fk = lca(x, y);
//			do
//			{
//				ans = max(ans, mp[x][par[x]]);
//				x = par[x];
//			}while (par[x] != fk);
			do
			{
				ans = max(ans, mp[y][par[y]]);
				y = par[y];
			}while (par[y] != fk);
			printf("%d\n", lastans = ans);
		}
	}
	return 0;
}
