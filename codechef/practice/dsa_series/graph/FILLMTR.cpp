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

const int mxn = 1e5;
vii g[mxn];
int color[mxn];
bool bad;

void init() {
    for(int i = 0; i < mxn; i++) {
        g[i].clear();
        color[i] = -1;
    }
    bad = 0;
}

void dfs(int u, int p, int c) {
    if(~color[u]) return;
    color[u] = c;
    for(auto v: g[u]) {
        if(v.first == p) continue;
        if(v.first == u) {
            if(v.second == 1) {
                bad = true;
                return;
            }
            continue;
        }
        if(color[v.first] != -1) {
            if(color[v.first] != abs(c - v.second)) {
                bad = true;
                return;
            }   
        }
        else dfs(v.first, u, abs(c - v.second));
    }
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
        int i, j, n, q;
        init();
        cin>>n>>q;
        rep(i, 0, q) {
            int x, y, c;
            cin>>x>>y>>c;
            x--, y--;
            g[x].pb({y, c});
            g[y].pb({x, c});
        }

        rep(i, 0, n) {
            if(color[i] == -1) {
                dfs(i, -1, 0);
                if(bad) break;
            }   
        }
        if(bad) cout<<"no\n";
        else cout<<"yes\n";
        
    }
   
    return 0;
}