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

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int i, j, k, n;
    cin>>n;
    int a[n][3], dp[n][3];

    rep(i, 0, n){
        rep(j, 0, 3){
            cin>>a[i][j];
        }
    }

    rep(i, 0, n){
        rep(j, 0, 3){
            if(!i) {
                dp[i][j] = a[i][j];
                continue;
            }
            dp[i][j] = 0;
            rep(k, 0, 3){
                if(j==k) continue;
                dp[i][j] = max(dp[i-1][k] + a[i][j], dp[i][j]);
            }
        }
    }

    int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout<<ans;
   
    return 0;
}