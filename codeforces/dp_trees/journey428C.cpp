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

const int mxN = 100001;

vector<int> g[mxN];
int numerator, denominator;

void dfs(int u = 0, int depth = 0){
    bool isleaf = (g[u].size()==0);

    if(isleaf){
        numerator += depth;
        denominator++;
        return;
    }    

    for(int v: g[u])
        dfs(v, depth+1);
}

int main(){
    int n;
    cin>>n;
    int i;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb(v);
    }

    dfs();

    cout<<fixed<<setprecision(11);
    
    cout<<numerator/float(denominator)<<endl;
    // cout<<numerator<<" "<<denominator<<endl;

    return 0;
}