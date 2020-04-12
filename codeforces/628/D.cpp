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
    ll u, v;
    cin>>u>>v;

    if(!u && !v){
        cout<<0;
        return 0;
    }

    if(u > v || (u&1 ^ v&1)){
        cout<<-1;
        return 0;
    } 

    if(u == v){
        cout<<"1\n"<<u;
        return 0;
    } 

    ll _and = (v-u)/2;

    ll x = (u+_and)^_and;
    if(x == u)
        cout<<"2\n"<<u+_and<<" "<<_and;
    
    else if( u^ _and ^_and == u)
        cout<<"3\n"<<u<<" "<<_and<<" "<<_and;
    
    else cout<<"-1";
    return 0;
}