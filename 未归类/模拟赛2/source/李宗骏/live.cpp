#include<cstdio>
using namespace std;

const int maxn=100000+5;
int n,cnt=0,nowon=0,a[maxn],on[maxn];

int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>nowon) cnt+=a[i]-nowon,nowon=a[i];
		else nowon-=cnt-a[i];
	}
	printf("%d",cnt);
	return 0;
}
