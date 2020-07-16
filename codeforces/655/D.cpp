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
    
   
    int i, j, n;
    cin>>n;
    set<pair<ll, int>> st;
    vector<ll> a(n);
    vector<int> prev(n), next(n);
    rep(i, 0, n) {
        prev[i] = (i-1+n)%n;
        next[i] = (i+1)%n;
        cin>>a[i];
        st.insert({a[i], i});
    }

    while(st.size() > 1){
        auto it = st.begin();
        ll x = it->first;
        int ind = it->second;
        int nxt = next[ind], prv = prev[ind];
        st.erase({a[nxt], nxt});
        st.erase({a[prv], prv});
        a[ind] = a[nxt] + a[prv];
        st.erase(it);
        st.insert({a[ind], ind});

        next[prev[prv]] = ind;
        prev[next[nxt]] = ind;
        // cerr<<x<<" "<<a[ind]<<"\n";
    }

    cout<<st.begin()->first;
      
    return 0;
}