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

int dfs(vi g[], int u, int par){

    int c = 1;
    for(int v: g[u]){
        if(v == par) continue;
        c += dfs(g, v, u);
    }
    return c;

}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while(T--){
        int i, j;
        int n, x;
        cin>>n>>x;
        vi g[n];
        int c = 0;
        rep(i, 0, n){
            int u, v;
            cin>>u>>v;
            if(u==x || v==x) c++;
        }

        if(c==0 || c==1 || (n-1)&1){
            cout<<"Ayush\n";
        }
        else{
            cout<<"Ashish\n";
        }
    }
    
    
   
    return 0;
}