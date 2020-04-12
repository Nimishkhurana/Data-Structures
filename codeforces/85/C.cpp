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
        int n;
        cin>>n;
        int i;
        ll a[n], b[n], diff[n];
        ll mn = 1e18, ind = -1;
        rep(i, 0, n){
            cin>>a[i]>>b[i];
        }

        a[n] = a[0], b[n] = b[0];
        ll total = 0;
        rep(i, 0, n){
            diff[i] = max(0LL, a[i+1] - b[i]);
            total += diff[i];
        }

        rep(i, 0, n){
            if(!i)
                mn = min(mn, total - diff[n-1] + a[i]);
            else mn = min(mn, total - diff[i-1] + a[i]);
        }

        cout<<mn<<"\n";
    }
    return 0;
}