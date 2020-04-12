#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        int a[n], b[n];
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, n) cin>>b[i];

        bool pos = 0, neg = 0;
        rep(i, 0, n){
            if(a[i] < b[i] && !pos) break;
            else if(a[i] > b[i] && !neg) break;

            if(a[i] < 0) neg = 1;
            else if(a[i] > 0) pos = 1;
        }

        if(i == n) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}