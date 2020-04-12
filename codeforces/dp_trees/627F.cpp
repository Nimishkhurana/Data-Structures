#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define pb push_back
#define mk make_pair

const int mxN = 2e5+1;
int dp[mxN], a[mxN], ans[mxN];
vector<int> g[mxN];

void dfs1(int u = 0, int p = -1){
    dp[u] = a[u];

    for(int v: g[u]){
        if(v==p) continue;

        dfs1(v,u);

        dp[u] += max(dp[v], 0);
    }
}

void dfs2(int u = 0, int p = -1, int pd = 0){
    ans[u] = dp[u] + pd;

    for(int v: g[u]){
        if(v==p) continue;

        dfs2(v,u, max(0, ans[u] - max(0,dp[v])));
    }
}

int main(){
    int n;
    cin>>n;
    int i;
    rep(i,0,n){
        cin>>a[i];
        if(!a[i]) a[i] = -1;
    }

    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs1();
    dfs2();

    rep(i,0,n)
        cout<<ans[i]<<" ";
    
}