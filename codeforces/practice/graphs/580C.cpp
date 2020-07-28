//Author: nimishkhurana
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<int,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define INF 1000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 1e5;
bool cat[mxn];
vector<int> g[mxn];
int n, m, ans;

void dfs(int u = 0, int p = -1, int c = 0, int mx = 0) {
    // cerr<<u<<" "<<c<<" "<<mx<<"\n";
    bool leaf = true;
    if(cat[u]) c++;
    else c = 0;
    mx = max(c, mx);
    for(int v: g[u]) {
        if(v == p) continue;
        
        leaf = false;
        dfs(v, u, c, mx);
    }

    if(leaf && mx <= m) {
        ans++;
    }
}

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i;
    cin>>n>>m;
    rep(i, 0, n) 
        cin>>cat[i];
    rep(i, 0, n-1) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs();
    cout<<ans;
    return 0;
}