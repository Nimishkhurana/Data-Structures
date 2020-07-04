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

ll mss(vl &v) {
    ll ans = 0, cur = 0;
    int i;
    rep(i, 0, (int)v.size()) {
        cur = max(cur + v[i], v[i]);
        cur = max(0LL, cur);
        ans = max(cur, ans);
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
        int i, j, n;
        cin>>n;
        ll a[n];
        vl v1, v2;
        ll ans = 0;
        rep(i, 0, n) {
            cin>>a[i];
            if(i%2==0) ans += a[i];
        }
        for(i = 0; i < n-1; i+=2) {
            v1.pb(a[i+1] - a[i]);
        }
        for(i = 1; i < n-1; i+=2) {
            v2.pb(a[i] - a[i+1]);
        }

        // for(int x: v1) cerr<<x<<" ";
        // cerr<<"\n";

        // for(int x: v2) cerr<<x<<" ";
        // cerr<<"\n";

        // cerr<<ans<<"\n";
        ans += max(mss(v1), mss(v2));
        cout<<ans<<"\n";
    }
   
    return 0;
}