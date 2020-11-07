#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 10;

int a[maxn][maxn], ans;
bool vis[3][30];
void dfs(int x, int sum)
{
	if (x > 8)	ans = max(ans, sum);
	else for (int i = 1; i <= 8; i++)
		if (!vis[0][i] && !vis[1][x + i] && !vis[2][x - i + 8])
		{
			vis[0][i] = vis[1][x + i] = vis[2][x - i +8] = true;
			dfs(x + 1, sum + a[x][i]);
			vis[0][i] = vis[1][x + i] = vis[2][x - i +8] = false;
		}
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				scanf("%d", &a[i][j]);
		ans = 0;
		memset(vis, false, sizeof(vis));
		dfs(1, 0);
		printf("%5d\n", ans); 
	}
	return 0;
}

