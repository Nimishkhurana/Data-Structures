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
        int i, j;
        int n, m, k;
        cin>>n>>m>>k;
        int nj = n - m;
        int gets = n / k;
        int mxj = min(gets, m);
        int mxnj = gets - mxj;
        nj -= mxnj;
        m -= mxj;
        int mx2j = (m + (k - 1) - 1)/(k-1);
        cerr<<mxj<<" "<<mx2j<<"\n";
        cout<<mxj - mx2j<<"\n";
    }
   
    return 0;
}