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
    int rootColor = 0; //{0->B, 1->R}
    while(T--){
        int i, j;
        int x, y;
        string type;
        cin>>type;

        if(type == "Qi") {
            rootColor = 1 - rootColor;
        }
        else {
            cin>>x>>y;
            int lvlx = log2(x), lvly = log2(y);
            int xColor = lvlx&1? 1-rootColor: rootColor;
            int yColor = lvly&1? 1-rootColor: rootColor;
            int cnt[2];
            cnt[0] = cnt[1] = 0;
            while(x != y) {
                if(x > y) {
                    cnt[xColor]++;
                    xColor = 1 - xColor;
                    x >>= 1;
                }
                else if(y > x) {
                    cnt[yColor]++;
                    yColor = 1 - yColor;
                    y >>= 1;
                }
            }
            cnt[xColor]++;
            if(type == "Qr") {
                cout<<cnt[1]<<" ";
            }
            else {
                cout<<cnt[0]<<" ";
            }
        }
        
    }
   
    return 0;
}