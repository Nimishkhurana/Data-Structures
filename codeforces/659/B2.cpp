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

const int mxn = 1e5;

// ll dp[mxn+1][2], a[mxn]; //{inc, dec}
// ll n, k, l;

// void solve(int i, ll w1, ll w2) {
    
//     if(l - a[i] > k) {
//         dp[i][0] = dp[i][1] = INF;
//     }

//     w1
// }


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
        int n, k, l;
        cin>>n>>k>>l;
        ll a[n];
        rep(i, 0, n) {
            cin>>a[i];
        }

        ll mn = a[0];
        bool bad = a[0] > l;
        rep(i, 1, n) {
            if(a[i] < mn) {
                mn = a[i];
            }
            else {
                mn = a[i]+ p[t%(2*k)];
            }
            if(mn > l) {
                bad = 1;
                break;
            }
        }

        if(!bad) {
            cout<<"Yes\n";
        }
        else {
            cout<<"No\n";
        }

    }
   
    return 0;
}