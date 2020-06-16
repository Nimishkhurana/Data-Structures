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
#define INF 1000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

int n;
const int mxn = 1e5;
int h[mxn];
int dp[mxn];

int solve(int i){
    if(i==n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    if(i+1 == n-1)
        return dp[i] = abs(h[i+1] - h[i]);
    
    return dp[i] = min(abs(h[i+1] - h[i]) + solve(i+1), abs(h[i+2] - h[i]) + solve(i+2));
}

int solve_iterative(){
    int dp0 = 0;
    int dp1 = abs(h[1] - h[0]);

    for(int i = 2; i < n; i++){
        int temp = dp0;
        dp0 = dp1;
        dp1 = min(abs(h[i] - h[i-1]) + dp1, abs(h[i-2] - h[i]) + temp);
    }
    return dp1;
}

int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    memset(dp, -1, sizeof(dp));

    cin>>n;
    for(int i = 0; i < n; i++) cin>>h[i];

    cout<<solve_iterative();
   
    return 0;
}