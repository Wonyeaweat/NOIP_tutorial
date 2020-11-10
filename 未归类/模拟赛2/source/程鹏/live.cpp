#include <iostream>
#include <cstdio>
using namespace std;
int n, a[101010], ans;
int main(){
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", a+i);
	for(int i=1; i<=n; i++)
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%d\n", ans);
	return 0;
}
