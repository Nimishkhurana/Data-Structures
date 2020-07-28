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


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int i, j, n, p;
    cin>>n>>p;
    vector<pair<int, int>> g(n, {-1,-1});
    vector<bool> tank(n, true), tap(n, true);
    int u, v, d;
    rep(i, 0, p) {
        cin>>u>>v>>d;
        u--, v--;
        tap[u] = 0;
        tank[v] = 0;
        g[u] = {v,d};
    }
    int tanks = 0;
    rep(i, 0, n) {
        if(tank[i] && !tap[i]) tanks++;
    }
    cout<<tanks<<"\n";
    int mn;
    rep(i, 0, n) {
        if(!tank[i] || tap[i]) continue;
        u = g[i].first, mn = g[i].second;
        while(g[u].first != -1) {
            mn = min(mn, g[u].second);
            u = g[u].first;
        }
        cout<<i+1<<" "<<u+1<<" "<<mn<<"\n";
    }
    
    
   
    return 0;
}