#include <bits/stdc++.h>
using namespace std;
struct f{
	double w,v;
};
bool cmp(f x1,f x2){
	return x1.v*x2.w>x1.w*x2.v;
}
int n;
double t;
f a[110];
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].v;
	}
	sort(a+1,a+1+n,cmp);
	double wsum=0,vsum=0;
	int i;
	for(i=1;i<=n && a[i].w+wsum<=t;i++){
		vsum+=a[i].v;
		wsum+=a[i].w;
		//cout<<a[i].w<<" "<<a[i].v<<endl;
	}
	t-=wsum;
	if(t>0 && i<=n){
		vsum+=a[i].v*(t/a[i].w);
	}printf("%.2lf",vsum);
	return 0;
}
