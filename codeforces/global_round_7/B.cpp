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

int main(){
    fast 
    int T;
    T = 1;
    while(T--){
        int n;
        cin>>n;
        ll b[n], a[n];
        int i;
        rep(i,0,n) cin>>b[i];

        a[0] = b[0];
        ll mx = a[0];

        rep(i,1,n){
            a[i] = b[i]  + mx;
            mx = max(a[i], mx);
        }

        rep(i,0,n) cout<<a[i]<<" \n"[i==n-1];

    }
    return 0;
}