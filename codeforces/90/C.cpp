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
        string s;
        cin>>s;
        int cur = 0;
        int diff = 0;
        ll ans = 0;
        rep(i, 0, (int)s.length()) {
            if(s[i] == '+') diff++;
            else diff--;
            if(diff < 0) {
                ans += max(0, (i+1)*(abs(diff+1) - cur + 1));
                cur = max(cur, abs(diff+1)+1);
            }
            // cerr<<cur<<" "<<ans<<"  ";
        }
        // cerr<<"\n";
        cout<<ans+(int)s.length()<<"\n";
    }
   
    return 0;
}