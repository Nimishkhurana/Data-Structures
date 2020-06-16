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

const int mxn = 60;
int n, p;
int pref[4][mxn+1][mxn+1], quadrant[mxn+1][mxn+1], ans[mxn+1][mxn+1];

vi query_text(int q, int i, int j){
    // Query text for q+1th quadrant till opposite corner.
    if(i<1 || i>n || j<1 || j>n){
        assert(false);
    }
    if(q == 0){
        return{1, i, 1, n, j};
    }
    else if(q == 1){
        return{1, i, j, n, n};
    }
    else if(q == 2){
        return{1, 1, j, i, n};
    }
    else if(q==3){
        return{1, 1, 1, i, j};
    }
    else return {};
}

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int i, j, q;
        cin>>n>>p;
        
        rep(q, 0, 4){
            rep(i, 0, n+1){
                rep(j, 0, n+1){
                    pref[q][i][j] = -1;
                }
            }
        }
        
        rep(i, 0, n+1){
            rep(j, 0, n+1){
                if(i <= n/2 && j > n/2){
                    // First quadrant
                    quadrant[i][j] = 0;
                }
                else if(i <= n/2 && j <= n/2){
                    // Second quadrant
                    quadrant[i][j] = 1; 
                }
                else if(i > n/2 && j <= n/2){
                    // Third quadrant
                    quadrant[i][j] = 2; 
                }
                else{
                    //Forth quadrant
                    quadrant[i][j] = 3;
                }
                ans[i][j] = 0;
            }
        }
        bool bad = false, done = false;;
        int queries = 0;
        auto setPref = [&](int q, int i, int j){
            if(bad || done) return;

            if(pref[q][i][j] == -1){
                // Make a Query
                for(int x: query_text(q, i, j))
                    cout<<x<<" ";
                cout<<"\n";
                int response;
                cin>>response;
                queries++;
                if(response == -1){
                    bad = true;
                    if(queries >= 5*n*n) assert(false);
                }
                pref[q][i][j] = response;
                if(q==0){
                    if(i==1) pref[3][n][j] = response;
                    if(j==n) pref[1][i][1] = response;
                }
                else if(q==1){
                    if(i==1) pref[2][n][j] = response;
                    if(j==1) pref[0][i][n] = response;
                    if(i==1 && j==1){
                        pref[0][1][n] = response;
                        pref[2][n][1] = response;
                        pref[3][n][n] = response;
                    } 
                }
                else if(q==2){
                    if(i==n) pref[1][1][j] = response;
                    if(j==1) pref[3][i][n] = response;
                }
                else if(q==3){
                    if(i==n) pref[0][1][j] = response;
                    if(j==n) pref[2][i][1] = response;
                }
            }
        };

        int infected_count = 0;
        
        auto query = [&](int i, int j){
            int q = quadrant[i][j];
            setPref(q, i, j);
            int infected;
            if(q==0){
                setPref(q, i, j-1);
                setPref(q, i+1, j);
                setPref(q, i+1, j-1);
                ans[i][j] = pref[q][i][j] + pref[q][i+1][j-1] - pref[q][i][j-1] - pref[q][i+1][j];
            }
            else if(q==1){
                setPref(q, i, j+1);
                setPref(q, i+1, j);
                setPref(q, i+1, j+1);
                ans[i][j] = pref[q][i][j] + pref[q][i+1][j+1] - pref[q][i][j+1] - pref[q][i+1][j];
            }
            else if(q==2){
                setPref(q, i, j+1);
                setPref(q, i-1, j);
                setPref(q, i-1, j+1);
                ans[i][j] = pref[q][i][j] + pref[q][i-1][j+1] - pref[q][i][j+1] - pref[q][i-1][j];
            } 
            else if(q==3){
                setPref(q, i, j-1);
                setPref(q, i-1, j);
                setPref(q, i-1, j-1);
                ans[i][j] = pref[q][i][j] + pref[q][i-1][j-1] - pref[q][i][j-1] - pref[q][i-1][j];
            } 

            if(ans[i][j]){
                infected_count++;
                if(infected_count > (n*n*p)/100){
                    done = true;
                }
            }
        };
        
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                // cerr<<"\n"<<i<<" "<<j<<" "<<quadrant[i][j]<<"\n";
                if(bad) return 0;
                if(done) break;
                query(i, j);
            }
            if(done) break;
        }

        cout<<"2\n";
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                assert(ans[i][j] == 0 || ans[i][j] == 1);
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }

        int valid;
        cin>>valid;
        if(valid==-1){
            return 0;
        }
    }
   
    return 0;
}