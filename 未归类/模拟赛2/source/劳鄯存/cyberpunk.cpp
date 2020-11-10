#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int ans;
int n, m;
int a[200];

int DFS(int val, int step){
	if (step == n+1 && val == m){
		ans++;
		return 0;
	}
	if (step == n+1 || val > m)
		return 0;
	for (int i = 0; i <= a[step]; i++){
		if (i>m) break;
		DFS(val+i,step+1);
	}
	return 0;
}

int main(){
	freopen("cyberpunk.in", "r",stdin );
	freopen("cyberpunk.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	DFS(0, 1);
	cout << ans << endl;
	return 0;
}
