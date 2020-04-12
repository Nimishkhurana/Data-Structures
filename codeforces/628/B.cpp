#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fast 
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll a[n];
        ll i;
        rep(i,0,n) cin>>a[i];
        unordered_set<ll> s(a, a+n);

        cout<<s.size()<<endl;
    }
    return 0;
}