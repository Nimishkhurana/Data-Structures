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
#define MOD 1000000009
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}
const int mxn = 2e6+1;

ll dp[mxn][3], ans[mxn];
int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        dp[1][0] = 1;
        cerr<<"h";
        rep(i, 2, n+1){
            dp[i][1] = dp[i-1][0];
            dp[i][0] = dp[i-1][0] + (2*dp[i-1][1]);
            dp[i][2] = dp[i-1][1];
            cerr<<dp[i][1]<<" ";
            ans[i] = ((dp[i][2] + 2 - 1)/2) * dp[i][1];
            cerr<<i<<" ";
        }
        cerr<<"\n";
        cerr<<dp[n][0]<<" "<<dp[n][1]<<" "<<dp[n][2]<<"\n";
        cout<<ans[n]<<"\n";
    }
   
    return 0;
}