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
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        ll i, j, n, k;
        cin>>n>>k;
        ll a[n];
        rep(i, 0, n) cin>>a[i];
        sort(a, a + n, greater<int>());
        i = 0;
        ll sum = 0, ans = 0;
        while(i < n){
            sum += a[i];
            if(sum >= (i+1)*k)
                ans++;
            else break;
            // cout<<i<<" "<<sum<<"\n";
            i++;
        }

        cout<<ans<<"\n";
    }
    return 0;
}