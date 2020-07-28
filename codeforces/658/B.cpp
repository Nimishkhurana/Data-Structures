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

const int mxn = 1e5;
int a[mxn], dp[mxn][2];
int n;
bool dfs(int i, bool twice) {
    // cerr<<i<<" "<<twice<<"\n";
    if(i == n-1) {
        return dp[i][twice] = true;
    }
    if(~dp[i][twice]) {
        return dp[i][twice];
    }
    bool willWin = false;
    willWin = !dfs(i+1, a[i+1] > 1);
    if(willWin) {
        return dp[i][twice] = true;
    }
    if(twice) {
        willWin = !dfs(i, false);
    }
    return dp[i][twice] = willWin;
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
        cin>>n;
        
        rep(i, 0, n) cin>>a[i];
        memset(dp, -1, sizeof(dp));
        if(dfs(0, a[0] > 1)) {
            cout<<"First"<<"\n";
        }else {
            cout<<"Second\n";
        }
    }
   
    return 0;
}