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

string solve(int x) {
    int t = x / 9;
    string ans = string(t, '9');
    // cerr<<ans<<"\n";
    if((t*9) < x){
        int y = x - t*9;
        string s = to_string(y);
        
        ans = s + ans;
    }
    return ans;
}

int f1(int x) {
    return (x*(x+1))/2;
}

int f2(int x) {
    int res = 0;
    int i;
    rep(i, 0, x) {
        res -= i;
    }
    return res;
}


bool less_than(string &cur, string &ans) {
    // cerr<<cur.length()<<" "<<ans.length()<<" ";
    if(cur.length() != ans.length()) {
        return cur.length() < ans.length();
    }
    for(int i = 0; i < (int)cur.length(); i++) {
        if(cur[i] < ans[i]) return true;
    }
    
    return false;
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
        int i, j, n, k;
        cin>>n>>k;
        string ans = "-1";
        rep(i, 0, 10) {
            int extra = 0;
            rep(j, i, i+1+k) {
                extra += (j%10 + j/10);
                // if(j < 10) extra += (j%10 + j/10);
                // else extra -= (j - 10);
            }
            
            int n2 = n - extra;
            cerr<<i<<" "<<extra<<" "<<n2<<"  ";
            if(n2 >= 0 && n2%(k+1)==0) {
                n2 = n2/(k+1);
                string cur = solve(n2);
                // cerr<<cur<<"\n";
                string s = to_string(i);
                cur = cur + s;
                if(ans == "-1" || less_than(cur, ans)){
                    ans = cur;
                }
                cerr<<cur<<" "<<ans<<"\n";
            }
            
        }
        // cerr<<ans<<" ";
        cout<<ans<<"\n";   
    }
   
    return 0;
}