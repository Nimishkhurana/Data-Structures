#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define pb push_back
#define mk make_pair

const int MAX = 1e5+2;
bool p[MAX];
vector<int> g[MAX];
int dp1[MAX], dp2[MAX];
void dfs1(int u, int par){

    dp1[u] = p[u]?0:INT_MIN;

    for(int child: g[u]){
        if(child == par) continue;

        dfs1(child, u);

        dp1[u] = max(dp1[u], dp1[child] + 1);
    }

}

void dfs2(int u, int par){
    
    int mx1 = INT_MIN, mx2 = INT_MIN;

    for(int child: g[u]){
        if(child == par) continue;

        if(dp1[child] > mx1){
            mx2 = mx1;
            mx1 = dp1[child];
        }

        else if(dp1[child] > mx2)
            mx2 = dp1[child];
    }

    for(int child: g[u]){
        if(child == par) continue;

        int use = mx1;
        if(mx1 == dp1[child])
            use = mx2;
        
        dp2[child] = max(dp2[u] + 1, use + 2);

        if(p[child]) dp2[child] = max(0, dp2[child]);

        dfs2(child, u);
    }
}


int main(){
    int n,m,d;
    cin>>n>>m>>d;
    int i,j,u,v;
    rep(i,0,m) cin>>u, p[u] = true;
    rep(i,1,n) cin>>u>>v, g[u].pb(v), g[v].pb(u);

    dfs1(1,0);
    dp2[1] = (p[1])?0:INT_MIN;

    dfs2(1,0);

    int count = 0;
    rep(i,1,n+1){
        // cout<<max(dp1[i],dp2[i])<<" ";
        if(dp1[i] <= d && dp2[i] <= d)
            count++;
    }
    
    cout<<count<<endl;
    return 0;

}