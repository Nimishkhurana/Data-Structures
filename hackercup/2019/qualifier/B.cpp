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

void solve() {
    string s;
    cin>>s;
    int cnt1 = 0, cnt2 = 0;
    for(char c: s) {
        if(c == 'B') cnt1++;
        else if(c == '.') cnt2++;
    }

    if(cnt1 >= min((int)s.length()/2, 2) && cnt2) cout<<"Y\n";
    else cout<<"N\n";
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("leapfrog_ch__input.txt", "r", stdin);
        freopen("leapfrog_ch__output2.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cout<<"Case #"<<t<<": ";
        solve();
    }
       
   
    return 0;
}