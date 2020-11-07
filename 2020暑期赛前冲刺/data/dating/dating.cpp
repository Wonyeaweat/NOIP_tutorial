#include <iostream>
#include <cstdio>
 
using namespace std;
 
int gcd (int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a%b);
}
 
int main() {
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	
	int x, y, a, b;
	scanf("%d %d %d %d", &x, &y, &a, &b);
	int t = x*y/gcd(x, y);
	int ans = b/t - a/t;
	if (a%t == 0) ans++;
	cout << ans <<endl;
	return 0;
}

