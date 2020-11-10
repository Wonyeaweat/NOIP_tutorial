#include<iostream>

using namespace std;

int n;
int a[100005];
long long ans, tmp;

int main(){
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++){
		if(tmp < a[i]){
			ans += (a[i] - tmp);
			tmp = a[i];
		} 
		if(a[i] < a[i - 1]) tmp = a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}
