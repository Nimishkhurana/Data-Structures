#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll unsigned long long
#define umap unordered_map<ll,ll>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

ll powBE(ll x, ll e){
    // Calculates x^e using Binary Exponentiation
    ll res = 1;
    while(e){
        if(e&1)
            res = (res*x);
        x = x*x;
        e/=2;  
    }
    return res;
}

ll lllog(ll base, ll x) {
    return (ll)(log2l(x) / log2l(base));
}

int main(){
    fast 
    ll T;
    cin>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;
        ll i, a[n];
        rep(i,0,n){
            cin>>a[i];
        } 

        sort(a, a+n, greater<ll>());
        umap vis;

        rep(i,0,n){
            ll x = a[i];
            // cout<<endl<<x<<"  ";
            while(x){
                ll l = lllog(k, x);
                // cout<<x<<" "<<l<<"  ";
                if(vis[l]) break;
                vis[l] = true;
                x = x%((ll)powBE(k,l));
            }
        
            if(x){
                cout<<"NO\n";
                break;
            }     
        } 
        
        if(i==n)
            cout<<"YES\n"; 
    }
    return 0;
}