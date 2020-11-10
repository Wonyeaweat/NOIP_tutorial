#include<iostream>
using namespace std;
int a,x[4],y[4],pri,cnt,ans=0x7f7f7f7f;
int main(){
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	cin>>a>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3];
	for(int i=1;i<=3;i++){
		cnt=0;
		pri=0;
		for(;;){
			cnt+=x[i];
			pri+=y[i];
			if(cnt>=a) break;
		}
		if(pri<ans) ans=pri;
	}
	cout<<ans;
	return 0;
}
