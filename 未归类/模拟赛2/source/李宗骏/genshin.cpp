#include<cstdio>
#include<algorithm>
using namespace std;

const int Minn=10000+5;
int n,Min=0x7fffffff,x[3],y[3];

int main(){
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(n%x[i]==0) Min=min(Min,y[i]*(n/x[i]));
		else Min=min(Min,y[i]*(n/x[i]+1));
	}
	printf("%d",Min);
	return 0;
}
