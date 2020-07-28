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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[2] = {0};
    for(char c: s) {
        cnt[c-'A']++;
    }
    if(abs(cnt[0] - cnt[1]) == 1) {
        cout<<"Y\n";
    }
    else {
        cout<<"N\n";
    }
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("alchemy_input.txt", "r", stdin);
    //     freopen("alchemy_output.txt", "w", stdout);
    // #endif
    
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cout<<"Case #"<<t<<": ";
        solve();
    }
       
   
    return 0;
}