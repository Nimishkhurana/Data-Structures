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
    
    int i, j, n, m;
    cin>>n>>m;
    // if(n*m < n+m){
    //     cout<<"0\n";
    //     return 0;
    // }
    if(n == 1 && m == 1){
        cout<<"0\n";
        return 0;
    }

    ll a[n+1][m+1];
    if(n <= m)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = i*(j+n);
            }
        }
    else
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = (i+m)*(j);
            }
        }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}