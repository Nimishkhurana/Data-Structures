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
        int a[2*n];
        rep(i, 0, 2*n) cin>>a[i];

        bool bad = false;
        int cnt = 0;
        vi inv;
        rep(i, 0, 2*n) {
            cnt = 0;
            rep(j, i, 2*n) {
                if(a[i] > a[j]) cnt++;
            }
            // cerr<<i<<" "<<cnt<<"\n";
            inv.pb(cnt);
        }

        if(is_sorted(inv.begin(), inv.end()) || is_sorted(inv.begin(), inv.end(), greater<int>())) {
            cout<<"YES\n";   
        }
        else cout<<"NO\n";
        // for(int x: inv) ce?rr<<x<<" ";
        cerr<<"\n";
        // if(bad) cout<<"NO\n";
        // else cout<<"YES\n";
    }
   
    return 0;
}