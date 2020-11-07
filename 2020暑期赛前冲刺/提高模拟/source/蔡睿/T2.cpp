#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define int long long 
#define tni int
const int maxn = 2505;
int a[maxn][maxn], n, t;
struct point
{
	int x, y;
}p[maxn * maxn];
struct n_bel
{
	int x, y;
}nb[maxn][maxn];
int fnt[maxn][maxn];
int ny[maxn][maxn];
void getit()
{
	int sum = n * n;
	a[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == 1 && j == 1) continue;
			if (j == 1) a[i][j] = (a[i - 1][j] - n + 1 + sum);
			else a[i][j] = (a[i][j - 1] + n);
			if (a[i][j] > sum) a[i][j] -= sum;
		}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			printf("%d ", a[i][j]);
//		printf("\n");
//	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			p[a[i][j]].x = i, p[a[i][j]].y = j;
	for (int i = 1; i <= n; i++)
		ny[i][n + 1 - i] = a[i][1], nb[i][1].x = i, nb[i][1].y = n - i + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= n; j++)
			nb[i][j].x = nb[i][j - 1].x + 1, nb[i][j].y = nb[i][j - 1].y + 1;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			printf("(%d, %d) ", nb[i][j].x, nb[i][j].y);
//		printf("\n");
//	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ny[nb[i][j].x][nb[i][j].y] = a[i][j];
//	for (int i = 1; i <= n * 2 - 1; i++)
//	{
//		for (int j = 1; j <= n * 2 - 1; j++)
//			printf("%d ", ny[i][j]);
//		printf("\n");
//	}
	for (int i = 1; i <= n * 2 - 1; i++)
		for (int j = 1; j <= n * 2 - 1; j++)
			fnt[i][j] = ny[i][j];
	for (int i = 1; i <= n * 2 - 1; i++)
		for (int j = 1; j <= n * 2 - 1; j++)
			fnt[i][j] += fnt[i - 1][j] + fnt[i][j - 1] - fnt[i - 1][j - 1];
//	for (int i = 1; i <= n * 2 - 1; i++)
//	{
//		for (int j = 1; j <= n * 2 - 1; j++)
//			printf("%d   ", fnt[i][j]);
//		printf("\n");
//	}
}
int getans(int x1, int y1, int x2, int y2)
{
	return fnt[x2][y2] - fnt[x2][y1] - fnt[x1][y2] + fnt[x1][y1];
}
signed main()
{
	freopen("T2.in", "r", stdin);
	freopen("T2.out", "w", stdout);
	scanf("%lld%lld", &n, &t);
	getit();
	int now = 1;
	while (t--)
	{
		int x;
		scanf("%lld", &x);
		now += x;
		if (now > n * n) now %= (n * n);
		int nx = p[now].x, nY = p[now].y;
		int real_x = nb[nx][nY].x, real_y = nb[nx][nY].y;
		int x1 = max((long long)1, real_x - x + 1), y1 = max((long long)1, real_y - x + 1);
		int x2 = min(n * 2 - 1, real_x + x - 1), y2 = min(n * 2 - 1, real_y + x - 1);
		int res = getans(x1 - 1, y1 - 1, x2, y2);
		printf("%lld\n", res);
	}
	return 0;
}
