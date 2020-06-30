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
    
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        ll k;
        cin>>k;
        map<ll,pair<ll,ll>> freq;
        rep(i, 0, n){
            ll x;
            cin>>x;
            freq[((k - x)%k+k)%k].first++;
            freq[((k - x)%k+k)%k].second = max(freq[((k - x)%k+k)%k].second, x);
        }
        ll ans = 0;
        for(auto p: freq){
            if(p.first == 0) continue;
            ans = max(ans, (p.second.second + (k-p.second.second%k) + (p.second.first-1)*k) - (p.second.second) + 1);
        }
        cout<<ans<<"\n";
    }
   
    return 0;
}