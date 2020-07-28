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
        int i, j;
        ll l, r, m, n, a = -1, b = -1, c = -1;
        cin>>l>>r>>m;
        ll mmin = m - (r - l);
        ll mmax = m - (l - r);
        // cerr<<mmin<<" "<<mmax<<"\n";
        rep(a, l, r+1) {
            // cerr<<a<<"\n";
            if(mmin%a == 0) {
                n = mmin/a;
                if(n == 0) n = 1;
                ll rem = m - a*n;
                if(rem <= 0)
                    c = r, b = r + rem;
                else
                    c = l, b = l + rem;
                if(n > 0 && l <= c && c <= r && l <= b && b <= r && a*n+b-c == m) {
                    break;
                }
            }
            else if(mmax%a == 0) {
                n = mmax/a;
                if(n == 0) n = 1;
                ll rem = m - a*n;
                // cerr<<rem<<" ";
                if(rem <= 0)
                    c = r, b = r + rem;
                else
                    c = l, b = l + rem;
                if(n > 0 && l <= c && c <= r && l <= b && b <= r && a*n+b-c == m) {
                    break;
                }
            }
            ll d1 = (mmin + a-1) / a;
            ll d2 = (mmax + a-1) / a;
            if(d1 != d2) {
                n = d1;
                if(n == 0) n = 1;
                ll rem = m - a*n;
                if(rem <= 0)
                    c = r, b = r + rem;
                else
                    c = l, b = l + rem;
                if(n > 0 && l <= c && c <= r && l <= b && b <= r && a*n+b-c == m) {
                    break;
                }
                n = (d1+d2)/2;
                if(n == 0) n = 1;
                rem = m - a*n ;
                if(rem <= 0)
                    c = r, b = r + rem;
                else
                    c = l, b = l + rem;
                if(n > 0 && l <= c && c <= r && l <= b && b <= r && a*n+b-c == m) {
                    break;
                }
            }
        }
        if(a == -1) assert(false);
        cout<<a<<" "<<b<<" "<<c<<"\n";
        // cerr<<a<<" "<<b<<" "<<c<<"\n";
    }
   
    return 0;
}