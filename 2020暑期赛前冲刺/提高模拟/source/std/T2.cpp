#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define fr freopen("T2.in", "r", stdin);
#define fw freopen("T2.out", "w", stdout);
ll b[2002][2002];
int a[1001][1001], x[1000005], y[1000005];
int main() {
    fr;
    fw; 
    int n,t;
    cin>>n>>t;
    int tot=0;
    const int K = n;
    for(int i=1;i<=n;++i) {
        int cur=i;
        for(int j=1;j<=n;++j) {
            a[j][cur]=++tot;
            b[j+cur][j-cur+K]=tot;
            x[tot]=j+cur;
            y[tot]=j-cur+K;
            cur=cur%n+1;
        }
    }
    for(int i=1;i<=2*n;++i) {
        for(int j=1;j<=2*n;++j) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }
    auto get = [&](int x1,int x2,int y1,int y2) -> ll {
        return b[x2][y2] - b[x2][y1-1] - b[x1-1][y2] + b[x1-1][y1-1];
    };
    int cur=1;
    for(int i=1;i<=t;++i) {
        int q;
        cin>>q;
        cur=(cur+q-1)%(n*n)+1;
        int xx = x[cur], yy = y[cur];
        int lx = max(xx-q+1, 1), rx = min(xx+q-1, 2*n), ly = max(yy-q+1, 1), ry = min(yy+q-1, 2*n);
        cout<<get(lx,rx,ly,ry)<<endl;
    }
}
