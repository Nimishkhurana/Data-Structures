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
#define INF 1000000000000

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 100, mxv = 1000;
ll dp[mxn][mxn*mxv+1]; //stores weight
int price[mxn];
ll weight[mxn];
int n;
ll w;

ll solve(int i, int val){
    if(val==0) return 0;
    if(i==n){
        return INF;
    }

    if(~dp[i][val]) return dp[i][val];

    ll &ans = dp[i][val];
    ans = solve(i+1, val);
    
    ll nxt = solve(i+1, val-price[i]);
    // if(nxt + weight[i] <= w)
        ans = min(ans, nxt + weight[i]);

    return ans;
}


int main(){
    fastIO
    
    cin>>n>>w;
    ll maxval = 0;
    for(int i = 0; i < n; i++){
        cin>>weight[i]>>price[i];
        maxval += price[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = maxval; i>=1; i--){
        if(solve(0, i) <= w){
            ans = i;
            break;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= maxval; j++){
    //         cerr<<dp[i][j]<<" ";
    //     }
    //     cerr<<"\n";
    // }

    cout<<ans;
   
    return 0;
}