#include <bits/stdc++.h>

using namespace std;
const int maxn = 10000 + 5;

int n, x, y, ans = maxn;

int main() {
	freopen("genshin.in", "r", stdin);
	freopen("genshin.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < 3; i++) {
		scanf("%d%d", &x, &y);
		int m = n / x;
		if(n % x) m++;
		ans = min(ans, m * y);
	}
	printf("%d\n", ans);
	return 0;
}
