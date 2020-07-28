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
#define MOD 1000000007
#define INF 1000000000
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
        int i, j;
        int a[3];
        rep(i, 0 ,3) cin>>a[i];
        
        if(a[0] == a[1] && a[0] >= a[2]) {
            cout<<"YES\n";
            cout<<a[0]<<" "<<a[2]<<" "<<a[2]<<"\n";
        }
        else if(a[0] == a[2] && a[0] >= a[1]) {
            cout<<"YES\n";
            cout<<a[0]<<" "<<a[1]<<" "<<a[1]<<"\n";
        }
        else if(a[1] == a[2] && a[1] >= a[0]) {
            cout<<"YES\n";
            cout<<a[1]<<" "<<a[0]<<" "<<a[0]<<"\n";
        }
        else {
            cout<<"NO\n";
        }
           
    }
   
    return 0;
}