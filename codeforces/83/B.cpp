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
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int i, a[n];
        rep(i,0,n) cin>>a[i];
        sort(a, a+n, greater<int>());
        rep(i,0,n) cout<<a[i]<<" ";
        cout<<endl; 
    }
    return 0;
}