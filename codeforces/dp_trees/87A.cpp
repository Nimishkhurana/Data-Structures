#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mxN = 2002;
vector<int> g[mxN];
int dp[mxN],ans;

// in dp : dp[i] = max height of node i.
void dfs(int u = 0){
    dp[u] = 1;

    for(int v: g[u]){
        dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }

    ans = max(ans, dp[u]);
}

int main(){
    int i,j,n;
    cin>>n;
    rep(i,0,n){
        int u;
        cin>>u;
        if(u==-1) u = 0;
        g[u].pb(i+1);
    }

    rep(j,0,g[0].size())
        dfs(g[0][j]);
    
    cout<<ans<<endl;
    
}