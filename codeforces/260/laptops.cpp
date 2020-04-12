#include<bits/stdc++.h>
#include <iomanip>
#include<map>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>

int main(){
    ll n;
    cin>>n;
    ll p, q;

    for(ll i=0;i<n;i++){
        cin>>p>>q;
        if(p!=q){
            cout<<"Happy Alex";
            exit(0);
        }
    }
    cout<<"Poor Alex";
    return 0;
}