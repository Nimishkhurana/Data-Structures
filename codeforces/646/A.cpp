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
    
    int i, j;
    int n, x;
    cin>>n>>x;
    
    int a[n];
    rep(i, 0, n) cin>>a[i];

    int odds = 0, evens = 0;
    rep(i, 0, n){
        if(a[i]&1) odds++;
        else evens++;
    }
    
    if(x%2==0 && evens==0){
        cout<<"NO\n";
        continue;
    }
    x -= evens;
    x = max(x, 1);
    if(x%2==0) x++;
    if(odds >= x) cout<<"YES\n";
    else cout<<"NO\n";

    }
   
    return 0;
}