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

void solve() {
    int i, n;
    cin>>n;
    ll p, h;
    unordered_map<ll, ll> mp;
    vll a(n);
    rep(i, 0, n) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end());
    for(auto pp: a) {
        ll p = pp.first, h = pp.second;
        auto it = mp.find(p);
        if(it != mp.end()) {
            mp[p+h] = max(mp[p+h], it->second + h);
        }
        else {
            mp[p+h] = max(mp[p+h], h);
        }
        it = mp.find(p-h);
        if(it != mp.end()) {
            mp[p] = max(mp[p], it->second + h);
        }
        else {
            mp[p] = max(mp[p], h);
        }
    }
        
    ll ans = 0;
    for(auto p: mp) {
        ans = max(ans, p.second);
    }
    cout<<ans<<"\n";
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("timber_input.txt", "r", stdin);
    //     freopen("timber_output.txt", "w", stdout);
    // #endif
    
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cout<<"Case #"<<t<<": ";
        solve();
    }
    
    return 0;
}