#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;

int n;
int a, b, ans;

int main() {
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		if(b < a) ans += a - b;
		b = a;
	}
	printf("%d\n", ans);
	return 0;
}
