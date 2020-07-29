//Author: nimishkhurana // WA
#include<bits/stdc++.h>
using namespace std;
// Errichto debugging template
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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
#define INFI 1000000000
#define INFL 100000000000000
clock_t time_c = clock();
 
void timeElapsed() {
    time_c = clock()-time_c;
    cerr<< " [Time Elapsed: "<<(float)(time_c)/CLOCKS_PER_SEC<<"]\n";
}

//<------------------------------------------------------------------------------------------->


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
        ll n, k, l1, r1, l2, r2;
        cin>>n>>k;
        cin>>l1>>r1;
        cin>>l2>>r2;
        ll k2 = k;
        if(r1 > r2) {
          swap(l1, l2);
          swap(r1, r2);
        }

        auto overlap = [&] (ll l1, ll r1, ll l2, ll r2) {
          return r1 - max(l1, l2);
        };

        ll cost = INT_MAX, cur;
        ll tcost = max(0LL, l2 - r1);
        ll ov = -min(l1, l2) + max(r2, r2);
        ll curOverlap = max(0LL, overlap(l1, r1, l2, r2));
        ll ocost = ov - curOverlap;
        k -= min(k, curOverlap*n);
     
        // case  1 open
        cur = tcost + min(ocost, k);
        k -= min(ov, k);
        cur += 2*k;
        cost = min(cost, cur);
        // case 2 open all first
        cur = 0, k = k2;
        ll to = min(n, k / ov);
        cur = to * (tcost + ocost);
        k -= (to * ov);
        
        debug() << imie(k);
        if(k > 0) {
          if(to < n) {
            cost = min({2*k+cur, cost});
            cur += tcost;
            cur += k;
            cost = min(cost, cur);
          }
          else {
            cur += 2*k;
            cost = min(cost, cur);
          }
        }

         // case 2 open all first
        cur = 0, k = k2;
        
        

        cout<<cost<<"\n"; 
    }
   
    return 0;
}