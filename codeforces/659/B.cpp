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

const int mxn = 101;;
int n, k, l;
int a[mxn], p[2*mxn];
bool can;
int dp[mxn][2*mxn*mxn];
bool solve(int i, int t) {
    if(i == n) {
        can = 1;
        return true;
    }
    if(~dp[i][t]) {
        return dp[i][t];
    }
    int cur = a[i] + p[t%(2*k)];
    if(cur > l) {
        return dp[i][t] = false;
    }
    return dp[i][t] = (solve(i+1, t+1) || solve(i, t+1));
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
        int i, j;
        cin>>n>>k>>l;
        rep(i, 0, n) cin>>a[i];
        memset(dp, -1, sizeof(dp));
        rep(i, 0, k+1) {
            p[i] = i;
        }
        int t = k-1;
        rep(i, 0, k) {
            p[i+k+1] = t--;
        }

        can = 0;
        rep(i, 0, 2*k) {
            solve(0, i);
        }
        
        if(can) {
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }
    }
   
    return 0;
}