#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	int n=100;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i*i+j*j<=n*n) ans++;
	ans*=4;
	cout<<ans;
	return 0;
} 
