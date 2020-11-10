#include<iostream>
#include<cstdio>

using namespace std;

int n, minn = 100000005;
int w[5], v[5];

int min(int a, int b){
	return a > b ? b : a;
}

int up(int a, int b){
	return a % b == 0 ? a / b : a / b + 1;
}

int main(){
	freopen("genshin.in", "r", stdin);
	freopen("genshin.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < 3; i++) cin >> w[i] >> v[i];
	
	for(int i = 0; i < 3; i++) minn = min(minn, up(n, w[i]) * v[i]);
	
	cout << minn << endl;
	
	return 0;
}
