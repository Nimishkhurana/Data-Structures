#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll mod = 998244353;

int main(){
    fast 
    ll i,n,k;
    cin>>n>>k;
    ll a[n], s = 0LL;
    vector<ll> b;
    rep(i,0,n){
        cin>>a[i];
        if(a[i] > n-k){
            s += a[i];
            b.pb(i);
        }
    }

    sort(b.begin(), b.end());

    ll c = 1;
    rep(i,0,k-1){
        if(b[i+1] != b[i])
            c = ((c%mod)*((b[i+1] - b[i])%mod))%mod;
    }

    cout<<s<<" "<<c<<"\n";


    return 0;
}