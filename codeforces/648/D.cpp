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


void dfs(string a[], vector<vector<bool>> &vis, int i, int j, int n, int m){

    if(a[i][j] == '#') return;

    vis[i][j] = true;
    if(i && vis[i-1][j] == 0 && a[i-1][j] != '#'){
        dfs(a, vis, i-1, j, n, m);
    }
    if(j && vis[i][j-1] == 0 && a[i][j-1] != '#'){
        dfs(a, vis, i, j-1, n, m);
    }
    if(i<n-1 && vis[i+1][j] == 0 && a[i+1][j] != '#'){
        dfs(a, vis, i+1, j, n, m);
    }
    if(j<m-1 && vis[i][j+1] == 0 && a[i][j+1] != '#'){
        dfs(a, vis, i, j+1, n, m);
    }
}

int main(){
    // fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin>>T;
    while(T--){
        int i, j, n, m;
        cin>>n>>m;
        string a[n];
        rep(i, 0, n){
            cin>>a[i];
        }
        // cerr<<"H";

        bool f = 1;
        rep(i, 0, n){
            rep(j, 0, m){
                // cerr<<"H";
                if(a[i][j] == 'B'){
                    if(i){
                        if(a[i-1][j]=='G'){
                            f = 0;
                            break;
                        }
                        
                        else if(a[i-1][j]=='.') a[i-1][j] = '#';
                    }
                    // cerr<<"H";
                    if(j){
                        if(a[i][j-1]=='G'){
                            f = 0;
                            break;
                        }
                        else if(a[i][j-1]=='.') a[i][j-1] = '#';
                    }
                    // cerr<<"H";
                    if(i<n-1){
                        if(a[i+1][j]=='G'){
                            f = 0;
                            break;
                        }
                        else if(a[i+1][j]=='.') a[i+1][j] = '#';
                    }
                    // cerr<<"H";
                    if(j<m-1){
                        if(a[i][j+1]=='G'){
                            f = 0;
                            break;
                        }
                        else if(a[i][j+1]=='.') a[i][j+1] = '#';
                    }
                    // cerr<<"H";
                }
            }
        }

        if(!f){
            cout<<"NO\n";
            continue;
        }
        // cout<<"1\n";
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        dfs(a, vis, n-1, m-1, n, m);

        rep(i, 0, n){
            rep(j, 0, m){
                if(vis[i][j]==0 && a[i][j]=='G'){
                    f = 0;
                    break;
                }
            }
        }

        if(f){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
   
    return 0;
}