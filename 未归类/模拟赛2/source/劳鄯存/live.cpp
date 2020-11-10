#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[2000000];
int ans;

int main(){
	freopen("live.in", "r",stdin );
	freopen("live.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	ans = a[1];
	for (int i = 1; i < n; i++){
		if (a[i] < a[i+1]){
			ans = ans + a[i+1] - a[i];
		}
	}
	cout << ans << endl;
	return 0;
}
