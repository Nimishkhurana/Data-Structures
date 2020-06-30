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
        int i, j;
        int n, m, x, y;
        cin>>n>>m>>x>>y;
        char a[n][m];
        int cnt = 0;
        rep(i, 0, n){
            rep(j, 0, m){
                cin>>a[i][j];
                if(a[i][j] == '.') cnt++;
            }
        }

        if(2*x < y){
            cout<<cnt*x<<"\n";
            continue;
        }

        int cnt2 = 0;
        rep(i, 0, n){
            for(j = 0; j < m-1;){
                if(a[i][j] == '.'){
                    if(a[i][j+1] == '.') cnt2++;
                    j += 2;
                }
                else{
                    j++;
                }
            }
                
        }
        cerr<<cnt<<" "<<cnt2<<"\n";
        cout<<cnt2*y + (cnt-cnt2*2)*x<<"\n";

    }
   
    return 0;
}