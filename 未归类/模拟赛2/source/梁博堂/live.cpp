#include<iostream>
using namespace std;
int n,a[100005],ans,cnt;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ans=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
