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
#define fr freopen("T3.in", "r", stdin); 
#define fw freopen("T3.out", "w", stdout);
const int maxn = 100005;
int a[maxn];
struct edge {
    int v,w;
};
vector<edge> g[maxn];
int par[maxn],psz[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
int f[maxn][20], h[maxn][20], dep[maxn], dis[maxn];
void dfs(int u,int fa) {
    for(edge e : g[u]) {
        int v = e.v;
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        dis[v] = dis[u] + e.w;
        f[v][0] = u;
        h[v][0] = e.w;
        for(int i=1;i<=19;++i) {
            f[v][i] = f[f[v][i-1]][i-1];
            h[v][i] = max(h[v][i-1], h[f[v][i-1]][i-1]);
        }
        dfs(v, u);
    }
}
pair<int,int> lca(int u,int v) {
    int mx = 0;
    if(dep[u] < dep[v]) swap(u, v);
    for(int d=dep[u]-dep[v],i=19;i>=0;--i) if(d&(1<<i)) mx=max(mx,h[u][i]),u=f[u][i];
    if(u == v) return {u, mx};
    for(int i=19;i>=0;--i)
        if(f[u][i]!=f[v][i]) mx=max(mx,max(h[u][i],h[v][i])),u=f[u][i],v=f[v][i];
    mx=max(mx,max(h[u][0],h[v][0]));
    return {f[u][0], mx};
}
int32_t main() {
    fr;
    fw;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i) par[i]=i,psz[i]=1;
    for(int i=1;i<=m;++i) {
        int u,v,w;
        cin>>u>>v>>w;;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        int x=find(u),y=find(v);
        if(psz[x] > psz[y]) {
            swap(x, y), swap(u, v);
        }
        par[x] = y;
        psz[y] += psz[x];
    }
    for(int i=1;i<=n;++i) {
        if(find(i) == i) dfs(i, 0);
    }
    int ans = 0;
    while(q--) {
        int op;
        cin>>op;
        if(op == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            u^=ans, v^=ans, w^=ans;
            int x = find(u), y = find(v);
            if(psz[x] < psz[y]) {
                swap(x, y);
                swap(u, v);
            }
            par[y] = x;
            psz[x] += psz[y];
            dep[v] = dep[u] + 1;
            dis[v] = dis[u] + w;
            f[v][0] = u;
            h[v][0] = w;
            for(int i=1;i<=19;++i) {
                f[v][i] = f[f[v][i-1]][i-1];
                h[v][i] = max(h[v][i-1], h[f[v][i-1]][i-1]);
            }
            dfs(v, u);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        } else if(op == 2) {
            int u, v;
            cin >> u >> v;
            u^=ans, v^=ans;
            cout << (ans = dis[u] + dis[v] - 2*dis[lca(u,v).first]) << endl;
        } else if(op == 3) {
            int u, v;
            cin >> u >> v;
            u^=ans, v^=ans;
            cout << (ans = lca(u,v).second) << endl;
        }
    }
}
