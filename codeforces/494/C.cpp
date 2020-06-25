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
    
    int i, j, n, k;
    cin>>n>>k;
    int a[n];
    rep(i, 0, n) cin>>a[i];

    double cur = 0, l = k;
    double cur_avg = 0;

    double mx = 0;
    rep(i, 0, n-k+1){
        l = 0, cur = 0;
        rep(j, i, n){
            cur += a[j];
            l++;
            if(l >= k)
                mx = max(mx, cur/l);
        } 
    }

    cout<< fixed << setprecision(10);
    cout<<mx<<"\n";
   
    return 0;
}