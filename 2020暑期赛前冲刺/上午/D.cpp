#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 10000 + 5;

int a[maxn];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	priority_queue<int, vector<int>, greater<int> > pq;
	
	int i, ans;
	for(i = 0; i < n; i++) scanf("%d", a+i);
	for(i = 0; i < m; i++) pq.push(a[i]);
	while(!pq.empty()) {
		int time = pq.top(); pq.pop();
		ans = time;
		if(i < n) {
			pq.push(time + a[i++]);
		}
	}
	printf("%d\n", ans);
}
