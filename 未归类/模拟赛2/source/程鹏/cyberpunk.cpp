#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[110], put[110], ans;
int s[110];
void dfs(int step, int cos){
	if(cos>m)return;//¼ôÖ¦ÍòËê!!!!!!
	if(cos+s[step]<m)return;//rp-=INF;
	if(step>n){
		if(cos==m)ans++;
		return;
	}
	for(int i=0; i<=a[step]; i++){
		dfs(step+1, cos+i);
	}
}
int main(){
	freopen("cyberpunk.in", "r", stdin);
	freopen("cyberpunk.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)scanf("%d", a+i);
	for(int i=n; i>=1; i--)s[i]=s[i+1]+a[i];
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
