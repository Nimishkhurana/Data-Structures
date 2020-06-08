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

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 2e5;
vi g[mxn];
ll a[mxn];
int b[mxn], c[mxn];

ll cost;

pii dfs(int u, int par, ll mn){

    mn = min(mn, a[u]);

    pii rem = {0,0};
    if(b[u] > c[u]) rem.first = 1;
    else if(b[u] < c[u]) rem.second = 1;

    for(int v: g[u]){
        if(v == par) continue;
        pii c = dfs(v, u, mn);
        rem.first += c.first;
        rem.second += c.second;
    }

    ll take = min(rem.first, rem.second);
    cost += 2 * take * mn;
    rem.first -= take, rem.second -= take;

    return rem;
}

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   
    int i, j, n;
    cin>>n;
    
    rep(i, 0, n){
        cin>>a[i]>>b[i]>>c[i];
    }
    rep(i, 1, n){
        int u, v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    pii rem = dfs(0, -1, a[0]);

    if(rem.first || rem.second){
        cout<<"-1\n";
    }
    else{
        cout<<cost<<"\n";
    }
   
    return 0;
}