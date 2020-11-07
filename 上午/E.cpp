#include<string>
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 50 + 5;

string a[maxn];
bool vis[26];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	string input;
	cin >> input;
	for(int i = 0; i < n; i++) {
		if(a[i].substr(0, input.size()) == input && a[i] > input) {
			vis[a[i][input.size()] - 'A'] = 1;
		}
	}
	
	for(int i = 0; i < 32; i++) {
		int x = i - 3;
		if(0 <= x && x <= 25 && vis[x]) cout << (char)(x + 'A');
		else cout << '*';
		if(i % 8 == 7) cout << endl;
	}
}
