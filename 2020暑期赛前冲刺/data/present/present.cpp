#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MaxN = 1e5 + 5;
#define LL long long 
LL a,n,m,sum = 0;
int main(){
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
    scanf("%lld", &n);
    m=2147483647;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        if(a > 0) sum = sum + a;
        if(a % 2 != 0 && fabs(a) < m)
            m = fabs(a);
    }
    if(sum % 2 == 0) sum = sum - m;
    printf("%lld\n", sum);
    return 0;
}
