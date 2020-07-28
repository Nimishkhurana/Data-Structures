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
#define INF 10000000000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


ll mss(vl &a, int x, int n) {
    ll ans = 0;
    int j;
    // vector<vector<ll>> dp(n+1, vector<ll>(4)); //{prefix, start, bw, end, suffix}
    // for(int i = 1; i <= n; i++) {
    //     dp[i][0] = max(dp[i-1][0] + a[i-1], a[i-1]);
    //     dp[i][1] = max(dp[i-1][0] + a[i-1]*x, a[i-1]*x);
    //     dp[i][2] = max(max(dp[i-1][2], dp[i-1][1]) + a[i-1]*x, a[i-1]*x);
    //     // dp[i][3] = max(dp[i-1][2] + a[i-1]*x, a[i-1]*x);
    //     dp[i][3] = max(max(dp[i-1][3], dp[i-1][2]) + a[i-1], a[i-1]);
    //     rep(j, 0, 4) 
    //         cerr<<dp[i][j]<<" ";
        
    //     cerr<<"\n";
    //     ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    // }
    vector<vector<ll>> dp(n+1, vector<ll>(3)); //{prefix, bw, suffix}

    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0] + a[i-1], a[i-1]);
        dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]) + a[i-1]*x, a[i-1]*x);
        dp[i][2] = max(max(dp[i-1][1], dp[i-1][2]) + a[i-1], a[i-1]);
        // rep(j, 0, 3) {
        //     cerr<<dp[i][j]<<" ";
        // }
        // cerr<<"\n";
        ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    return ans;
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
        int i, j, n, x;
        cin>>n>>x;
        vector<ll> a(n);
        rep(i, 0, n) {
            cin>>a[i];
        }

        cout<<mss(a, x, n)<<"\n";

    }
   
    return 0;
}