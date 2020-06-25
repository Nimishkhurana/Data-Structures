//Author: nimishkhurana
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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        int a[2*n];
        vector<int> odds, evens;
        rep(i, 0, 2*n){
            cin>>a[i];
            if(a[i]&1) odds.pb(i+1);
            else evens.pb(i+1);
        }

        if(int(odds.size())&1){
            odds.pop_back();
            evens.pop_back();
        }
        else{
            if(!odds.empty()){
                odds.pop_back();
                odds.pop_back();
            }
            else{
                evens.pop_back();
                evens.pop_back();
            } 
        }

        cerr<<odds.size()<<" "<<evens.size()<<"\n";
        for(int i = 0; i < (int)odds.size()-1; i+=2){
            cout<<odds[i]<<" "<<odds[i+1]<<"\n";
        }
        for(int i = 0; i < (int)evens.size()-1; i+=2){
            cout<<evens[i]<<" "<<evens[i+1]<<"\n";
        }
    }
   
    return 0;
}