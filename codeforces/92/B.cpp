//Author: nimishkhurana
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
        int i, j, n, k, z;
        cin>>n>>k>>z;
        int a[n];
        rep(i, 0, n) cin>>a[i];
        int prefix[n+1], suffix[n+1];
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        rep(i, 1, n+1) {
            prefix[i] = prefix[i-1] + a[i-1];
        }
        rrep(i, n-1, 0) {
            suffix[i] = suffix[i+1] + a[i];
        }

        ll ans = 0, cur, moves, rem;
        // oscilate here
        rep(i, 0, min(k+1, n)) {
            cur = prefix[i+1];
            if(!i) {
                ans = max(ans, cur);
                continue;
            }
            rem = k - i;
            cerr<<rem<<" ";
            ll t1 = (rem+1)/2;
            if(z >= t1) {
                cur += t1*a[i-1];
                cur += (rem - t1)*a[i];
                rem = 0;
            }
            else {
                cur += z*a[i-1];
                cur += z*a[i];
                rem -= 2*z;
            }

            cur += (suffix[i+1] - suffix[min((ll)n, i+rem+1)]);
            ans = max(ans, cur);
            // cerr<<rem<<" "<<ans<<"\n";
        }

        // ans = max(ans)

        cout<<ans<<"\n";
    }
   
    return 0;
}