#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[10], v[10];
int ans = 2147483647;

int ceil(int a, int b){
	double x = a*1.0/(b*1.0);
	int al = x;
	if (x > al)
		return al+1;
	else return al;
}

int main(){
	freopen("genshin.in" ,"r",stdin );
	freopen("genshin.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= 3; i++){
		cin >> a[i] >> v[i];
	}
	for (int i = 1; i <= 3; i++){
		ans = min(ans, v[i]*ceil(n,a[i]));
	}
	cout << ans << endl;
	return 0;
}
