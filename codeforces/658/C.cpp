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

string a, b;

void op(int len) {
    
    for(int i = 0; i < len; i++) {
        if(a[i] == '0') {
            a[i] = '1';
        }
        else {
            a[i] = '0';
        }
    }
    // cerr<<a.substr(0, len)<<"\n";
    for(int i = 0, j = len-1; i < j; i++, j--) {
        swap(a[i], a[j]);
    }
    
    // reverse(a.begin(), a.begin() + len - 1);
    // cerr<<a.substr(0, len)<<"\n\n";

    
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
        
        cin>>a>>b;
        
        vector<int> res;
        for(int i = n-1; i>=0; i--) {
            if(a[i] != b[i]) {
                if(a[0] != a[i]) {
                    op(1);
                    res.pb(1);
                }
                res.pb(i+1);
                op(i+1);
            }
        }

        assert(a == b);
        cout<<(int)res.size()<<" ";
        for(int x: res) cout<<x<<" ";
        cout<<"\n";
    }
   
    return 0;
}