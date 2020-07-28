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
#define INF 1000000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 1e7+1;
ll cost[mxn], dp[mxn];

ll rec(int i, int m, int n) {
    // cerr<<i<<" \n";
    if(i >= n-1) {
        return 0LL;
    }

    if(~dp[i]) {
        return dp[i];
    }

    if(i + m >= n-1) {
        return dp[i] = cost[i];
    }

    ll minCost = INF;
    int j;
    rep(j, 1, m+1) {
        minCost = min(minCost, rec(i+j, m, n));
        // cerr<<i<<" "<<i+j<<" "<<cur<<"\n";
    }
    // cerr<<i<<" "<<minCost<<"\n";
    return dp[i] = minCost + cost[i];b
}

void solve() {
    int i, n, m;
    cin>>n>>m;
    // cerr<<n<<" "<<m<<"\n";
    memset(dp, -1, sizeof(dp));
    rep(i, 0, n) {
        cin>>cost[i];
        if(cost[i] == 0) cost[i] = INF;
    }
    cost[0] = 0;
    ll ans = rec(0, m, n);
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";    
}


int main(){
    // fastIO
    #ifndef ONLINE_JUDGE
        freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
        // freopen("running_on_fumes_chapter_1_output.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cout<<"Case #"<<t<<": ";
        solve();
    }
       
   
    return 0;
}