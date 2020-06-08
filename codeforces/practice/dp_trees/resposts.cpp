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

int main(){
    int n;
    cin>>n;
    int i,j;
    string u,v,t;
    unordered_map<string, int> depth;
    depth["polycarp"] = 1;
    int maxDepth = 1;
    rep(i,0,n){
        cin>>u>>t>>v;
        transform(u.begin(), u.end(), u.begin(), ::tolower);
        transform(v.begin(), v.end(), v.begin(), ::tolower);

        depth[u] = depth[v] + 1;
        maxDepth = max(maxDepth, depth[u]);
    }

    cout<<maxDepth<<endl;
    return 0;
}