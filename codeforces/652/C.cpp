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
        int i, j, n, k;
        cin>>n>>k;
        vi a(n), b(k);
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, k) cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        // rep(i, 0, n) cerr<<a[i]<<" ";

        vi mn(k), mx(k);

        int l = 0, r = n-1;
        ll ans = 0;
        rrep(i, k-1, 0){
            // cerr<<b[i]<<" ";
            if(b[i] > 2){
                break;
            }
            else{
                mx[i] = a[r];
                mn[i] = a[r - b[i] + 1];
                r -= b[i];
            }
            // cerr<<mn[i]<<" "<<mx[i]<<"  ";
            ans += (mn[i] + mx[i]);
            // cerr<<ans<<"\n";
        }
        rep(j, 0, i+1){
            // cerr<<b[j]<<" ";
            if(b[j] > 2){
                mn[j] = a[l];
                mx[j] = a[r];
                l += (b[j]-1);
                r--;
            }
            else{
                
            }
             // cerr<<mn[j]<<" "<<mx[j]<<"  ";
            ans += (mn[j] + mx[j]);
            // cerr<<ans<<"\n";
        }
        cout<<ans<<"\n";
    }
   
    return 0;
}