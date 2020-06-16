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
#define MOD 998244353

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 300, mxq = 300;
int val[mxq+1], avail[mxq+1];
 //dp[using first i coins][sum]
int n, q;

ll solve_iterative(){
    int i, j, k;
    ll dp[q+1][n+1] = {0LL};
    
    rep(i, 0, q+1)
        rep(j, 0, n+1)
            if(j==0) dp[i][j] = 1;
            else dp[i][j] = 0;
    
    rep(i, 1, q+1){
        rep(j, 1, n+1){
            rep(k,0, avail[i]+1){
                if(val[i]*k > j) break;
                dp[i][j] = (dp[i][j] + dp[i-1][j-val[i]*k]) % MOD;
            }
        }
    }

    rep(i, 1, n+1){
        cout<<dp[q][i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int i, j, k;
    cin>>n>>q;
    
    rep(i, 0, q){
        cin>>val[i+1]>>avail[i+1];
    }

    solve_iterative();

   
    return 0;
}