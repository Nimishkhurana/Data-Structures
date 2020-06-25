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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int i, j, n, q;
    cin>>n>>q;
    int avail[31];
    memset(avail, 0, sizeof(avail));
    ll a[n];
    rep(i, 0, n){
        cin>>a[i];
        avail[(int)log2(a[i])]++;
    }

    rep(i, 0, q){
        ll x;
        cin>>x;
        bool bad = 0;
        int cur = 0, ans = 0;
       
        rrep(j, (int)log2(x)+1, 0){
            // cerr<<j<<"\n";
            if(x >= (1<<j) && avail[j]){
                int can_take = min(avail[j], (int)x/(1<<j));
                ans += can_take;
                x -= can_take*(1<<j);
                // avail[j] -= can_take;   
            }
        }
                
        if(x) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    
    return 0;
}