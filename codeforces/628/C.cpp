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

const int mxN = 1e5 + 2;

vector<int> edges[mxN];

int main(){
    fast 
    int n;
    cin>>n;
    int i,u;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        edges[u].pb(i);
        edges[v].pb(i);
    }

    rep(u,1,n+1){
        if(edges[u].size() < 3)
            continue;
        
        int ans[n-1];
        memset(ans, -1, 4*(n-1));
        int j;
        rep(j,0,3)
            ans[edges[u][j]] = j;
    
        rep(i,0,n-1){
            
            if(ans[i]==-1)
                ans[i] = j++;

            cout<<ans[i]<<endl;
        }

        return 0;
    }

    rep(i,0,n-1)
        cout<<i<<endl;

    return 0;
}