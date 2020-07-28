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
        int i, j, n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        int ans = 0;
        vector<int> ind[21];
        rep(i, 0, n) {
            ind[b[i]-'a'].pb(i);
        }

        auto update = [&] (set<char> &s, string &a, char c) {
            for(int i = 0; i < a.size(); i++) {
                if(s.find(a[i])!=s.end()) a[i] = c;
            }
        };

        bool bad = 0;
        rep(i, 0, 20) {
            if(ind[i].empty()) continue;
            set<char> s;
            for(int x: ind[i]) {
                if(a[x] > (i+'a')) {
                    bad = 1;
                    break;
                }
                if(a[x] != (i+'a'))
                    s.insert(a[x]);
            }
            update(s, a, (char)(i+'a'));
            ans += (int)s.size();
            cerr<<a<<"\n";
        }

        if(bad) {
            cout<<"-1\n";
        }
        else cout<<ans<<"\n";
    }
   
    return 0;
}