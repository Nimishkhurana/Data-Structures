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
    string in, out;
    cin>>in>>out;
    bool reach[n][n];
    memset(reach, 0, sizeof(reach));
    for(int i = 0; i < n; i++) {
        reach[i][i] = 1;
        if(in[i]=='Y') {
            if(i+1 < n && out[i+1]=='Y') reach[i+1][i] = 1;
            if(i && out[i-1]=='Y') reach[i-1][i] = 1;
        }
        if(out[i]=='Y') {
            if(i+1 < n && in[i+1]=='Y') reach[i][i+1] = 1;
            if(i && in[i-1]=='Y') reach[i][i-1] = 1;
        }
    }
    for(int len = 2; len < n; len++) {
        for(int i = 0; i+len < n; i++) {
            reach[i][i+len] = reach[i][i+len-1] && reach[i+len-1][i+len];
        }
        for(int i = n-1; i-len >= 0; i--) {
            reach[i][i-len] = reach[i][i-len+1] && reach[i-len+1][i-len];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(reach[i][j]) cout<<"Y";
            else cout<<"N";
        }
        cout<<"\n";
    }
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("travel_restrictions_input.txt", "r", stdin);
    //     freopen("travel_restrictions_output.txt", "w", stdout);
    // #endif
    
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++){
        cout<<"Case #"<<t<<":\n";
        solve();
    }
       
   
    return 0;
}