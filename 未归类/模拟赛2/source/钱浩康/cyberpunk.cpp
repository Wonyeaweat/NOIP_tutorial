#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 5;

long long ans;
int n, m;
int s[maxn];
int cnt[maxn];

void dfs(int id, int all) {
	if(all == m) {
		ans++;
		return;
	}
	for(int i = id; i < n; i++) if(cnt[i] + 1 <= s[i]) {
		cnt[i]++,
		dfs(i, all + 1);
		cnt[i]--;
	}
	return;
}

int main() {
	freopen("cyberpunk.in", "r", stdin);
	freopen("cyberpunk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", &s[i]);
	dfs(0, 0);
	printf("%lld\n", ans);
	return 0;
}
