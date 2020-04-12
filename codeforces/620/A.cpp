#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>
#define pb push_back

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        ll speed = a+b;
        ll dist = y - x;

        if(dist % speed != 0)
            cout<<-1<<endl;
        else
            cout<<dist/speed<<endl;
    }
    return 0;
}