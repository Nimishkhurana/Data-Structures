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
#define debug(x) cout << #x << " : " << x << endl;
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

const int mxn = 1e5;
// int dp[mxn+1][20][27];
int solve(string &s, int start, int lgsz, char c, int n) {
    // cerr<<start<< " "<< lgsz<<" "<<c<<"\n\n";
    if(lgsz < 0 || start >= n) {
        return 0;
    }

    // if(~dp[start][lgsz][c-'a']) {
    //     return dp[start][lgsz][c-'a'];
    // } 

    if(lgsz == 0) {
        int cost1 = (s[start] != c) + (s[start+1] != (c+1));
        int cost2 = (s[start+1] != c) + (s[start] != (c+1));
        // cerr<<"C1: "<<cost1<<"\n";
        // cerr<<"C2: "<<cost2<<"\n";
        return min(cost1, cost2);
    }
    
    // cerr<<"H ";
    

    int curCost = INF, cost1 = 0, cost2 = 0;
    int i;
    // cerr<<"H ";
    if(start + (1<<lgsz) <= n) {
        rep(i, start, start + (1<<lgsz)) {
            cost1 += (s[i] != c);
        }
        // cerr<<"C1: "<<cost1<<"\n";
    }
    else {
        cost1 = INF;
    }
    
    if(start + (1<<(lgsz+1)) <= n) {
        rep(i, start + (1<<lgsz), start + (1<<(lgsz+1))) {
            cost2 += (s[i] != c);
        }
        // cerr<<"C2: "<<cost2<<"\n";
    }
    else {
        cost2 = INF;
    }
    //(c != ('a' + log2(n)-1)
    cost1 += solve(s, start + (1<<lgsz), lgsz - 1, c+1, n);
    cost2 += solve(s, start, lgsz - 1, c+1, n);
    // cerr<<cost1<<" "<<cost2<<"\n";

    int ans =  min(cost1, cost2);
    // cerr<<ans<<"\n";
    return ans;
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
        // memset(dp, -1, sizeof(dp));
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n == 1) {
            if(s[0] == 'a') {
                cout<<"0\n";
            }
            else {
                cout<<"1\n";
            }
        }
        else
            cout<<solve(s, 0, (int)log2(n)-1, 'a', n)<<"\n";
    }
   
    return 0;
}