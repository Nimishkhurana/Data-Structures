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
#define INF 1000000000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

int n, w;
const int mxn = 100, mxw = 1e5+1;
int weight[mxn];
ll price[mxn], dp[mxn][mxw];

ll solve(int i, int w){
    if(i==n){
        return 0LL;
    } 

    if(~dp[i][w]) return dp[i][w];

    dp[i][w] = solve(i+1, w);
    if(weight[i] <= w)
        dp[i][w] = max(dp[i][w], price[i] + solve(i+1, w - weight[i]));
    return dp[i][w];
}

int main(){
    fastIO
    int i, j;
    
    cin>>n>>w;
    
    rep(i, 0, n){
        cin>>weight[i]>>price[i];
        rep(j, 0, w+1)
            dp[i][j] = -1;
    }

    ll ans = solve(0, w);
    cout<<ans;

    return 0;
}