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

clock_t time_c=clock();
 
void timeElapsed() {
    time_c = clock()-time_c;
    cerr<< " Time : "<<(float)(time_c)/CLOCKS_PER_SEC<<"\n";
}

string s;
int n;

int solve(char a, char b) {
    // cerr<<a<<" "<<b<<"\n";
    char f = a;
    int cnt = 0;
    string s2;
    for(char c: s) {
        if(c == f) {
            cnt++;
            s2.pb(c);
            f = (f==a?b:a);
        }
    }
    // cerr<<cnt<<" ";
    if(s2.length() > 2)
        if(s2[s2.length()-2] != s2[0]) cnt--;
    return n - cnt;
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
        s.clear();
        cin>>s;
        n = s.length();
        int ans = max(0, n - 2);
        rep(i, 0, 10) {
            rep(j, 0, 10) {
                ans = min(ans, solve(i+'0', j+'0'));
                ans = max(0, ans);
            }
        }
        cout<<ans<<"\n";
    }
   
    return 0;
}