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
    ll n;
    cin>>n;
    ll a[n], b[n];
    vector<ll> d(n);
    ll i;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,n)
        d[i] = a[i] - b[i];
    
    sort(d.begin(), d.end());

    ll count = 0;
    for(int l = 0, r = n-1;l < n; l++){
        while(r>=0 && d[l]+d[r]>0)
            r--;
        count+=n-1-r;
        cout<<count<<" ";
    }
    // cout<<endl;
    cout<<" "<<count/2<<endl;  
    
    return 0;
}