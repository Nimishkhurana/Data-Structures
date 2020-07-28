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

ll cnt[2];
void dfs(int u, int p, int c, vector<int> g[]) {
    cnt[c]++;
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u, 1-c, g);
    }
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    
    int i, j, n;
    cin>>n;
    vector<int> g[n];
    rep(i, 0, n-1) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1, 0, g);
    cout<<cnt[0]*cnt[1] - (n-1)<<"\n";
   
    return 0;
}