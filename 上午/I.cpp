#include<cstdio>
#include<iostream>
using namespace std;

const int maxn = 10100;

int n, cnt, ans[maxn][10], tmp[10];
void dfs(int x, int sum)
{
	if (x >= 10)
	{
		if (sum == n)
		{
			cnt++;
			for (int i = 0; i < 10; i++)
				ans[cnt][i] = tmp[i];
		}
	}else for (int i = 1; i <= 3; i++)
		if (sum + i <= n)
		{
			tmp[x] = i;
			dfs(x+1, sum+i);
		}
}
int main()
{
	scanf("%d", &n);
	cnt = 0;
	dfs(0, 0);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][9]);
	}
	return 0;
}

