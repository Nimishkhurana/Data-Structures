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

struct Node {
    int vertex, dist, vis; 
    Node(int v, int d, int vis): vertex(v), dist(d), vis(vis){}

    bool operator < (const Node &n) const {
        return dist < n.dist;
    }
};

void solve() {
    int n, m ,k;
    cin>>n>>m>>k;
    // cerr<<n;
    vector<Node> g[n];
    vii minDist(n, {INF, -1});
    int u, v, w;

    priority_queue<Node> pq;
    for(int i = 0; i < k; i++) {
        cin>>u;
        u--;
        pq.push(Node(u, 0, u));
        minDist[u] = {0, u};
    }

    for(int i = 0; i < m; i++) {
        cin>>u>>v>>w;
        u--, v--;
        g[u].pb(Node(v, w, 0));
        g[v].pb(Node(u, w, 0));
    }
    // cerr<<"h";
    
    int ans = INF;
    bool ok = 1;
    while(ok && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int u = top.vertex, d = top.dist;
        cerr<<"\n"<<u<<" "<<d<<"\n";
        ok = 0;
        for(auto &adj: g[u]) {
            int v = adj.vertex, w = adj.dist, vis = adj.vis;
            cerr<<v<<" "<<w<<" "<<vis<<"\n";
            int curDist = w + d;
            if(!vis && minDist[v].second ^ u) {
                ans = min(ans, curDist + minDist[v].first);
                // Node prev(v, minDist[v].first, minDist[v].second);
                adj.vis = true;
                ok = 1;

                if(minDist[v].first > curDist) {
                    minDist[v] = {curDist, u};
                    pq.push({v, w+d, u});
                }
                
            }
        }
    }
    cout<<ans<<"\n";
 
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    solve();
   
    return 0;
}