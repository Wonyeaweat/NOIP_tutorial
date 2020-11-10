#include <iostream>
#include <cstdio>
using namespace std;
int n, x, y, ans=10001*10001;
int main(){
	freopen("genshin.in", "r", stdin);
	freopen("genshin.out", "w", stdout);
	scanf("%d", &n);
	for(int k=1; k<=3; k++){
		scanf("%d%d", &x, &y);
		int cnt=0;
		for(int i=0; i<n; i+=x)cnt+=y;
		ans=min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
