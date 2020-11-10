#include <iostream>
using namespace std;
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
    int n,a,last=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>last)ans+=(a-last);
        last=a;
    }
    cout<<ans<<endl;
}
