#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define mp make_pair
const int maxn = 300030;
struct edge
{
	int to, nxt, val;
}e[maxn << 1];
int head[maxn], cnt;
int S[maxn], T[maxn];
void add(int x, int y, int z)
{
	e[++cnt].to = y;
	e[cnt].nxt = head[x];
	head[x] = cnt;
	e[cnt].val = z;
}
int vis[maxn], d[maxn];
void dij(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(d, 0x3f, sizeof(d));
	priority_queue< pair<int, int> > q;
	d[s] = 0, q.push(mp(0, s));
	while (q.size())
	{
		int x = q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = e[i].nxt)
		{
			int t = e[i].to, v = e[i].val;
			if (d[t] > d[x] + v)
			{
				d[t] = d[x] + v;
				if (!vis[t]) q.push(mp(-d[t], t));
			}
		}
	}
}
bool init[maxn];
int main()
{
	freopen("T1.in", "r", stdin);
	freopen("T1.out", "w", stdout);
	int n, m, P, Q;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z), add(y, x, z);
	}
	scanf("%d%d", &P, &Q);
	for (int i = 1; i <= P; i++) scanf("%d", &S[i]), init[S[i]] = 1;
	int ans = 0;
	for (int i = 1; i <= Q; i++)
	{
		int x;
		scanf("%d", &x);
		dij(x);
		int res = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++)
			if (init[j]) res = min(res, d[j]);
		ans += res;
	}
	printf("%d\n", ans);
	return 0;
}
