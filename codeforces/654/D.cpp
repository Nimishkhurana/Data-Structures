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
        int i, j, n, k;
        cin>>n>>k;

        int a[n][n], cnt = 0;
        memset(a, 0, sizeof(a));
      
        bool done = 0;
        for(int g = 0; g < n; g++) {
            for(int i = 0; i < n; i++) {
                if(cnt < k) {
                   a[i][(i+g)%n] = 1;
                   cnt++;
                }
            }
        }

        cout<<2*(k%n!=0)<<'\n';
        rep(i, 0, n){
            rep(j, 0, n){
                cout<<a[i][j];
            }
            cout<<"\n";
        }
    }
   
    return 0;
}