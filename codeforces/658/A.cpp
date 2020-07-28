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
        int i, j, n, m;
        cin>>n>>m;
        set<int> s;
        for(int i = 0; i < n; i++) {
            int x;
            cin>>x;
            s.insert(x);
        }
        bool done = 0;
        for(int i = 0; i < m; i++) {
            int x;
            cin>>x;
            if(!done && s.find(x) != s.end()) {
                cout<<"YES\n";
                cout<<"1 "<<x<<"\n";
                done = true;
            }
        }
        if(!done) {
            cout<<"NO\n";
        }
    }
   
    return 0;
}