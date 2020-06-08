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

int a[50][50];
int n, m;

bool isSafe(int i, int j){
    int c;
    rep(c, 0, n) if(a[c][j]) return false;
    rep(c, 0, m) if(a[i][c]) return false;
    return true;   
}

bool dfs(){
    int i, j;
    bool willLoose = true;
    rep(i, 0, n){
        rep(j, 0, m){
            if(isSafe(i, j)){
                a[i][j] = 1;
                bool nxt = dfs();
                a[i][j] = 0;
                if(nxt){
                    willLoose = false;
                    break;
                }
            }
        }
    }
    return willLoose;
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
        cin>>n>>m;
        int r[n], c[m];
        rep(i, 0, n) r[i] = 1;
        rep(i, 0, m) c[i] = 1;
        rep(i, 0, n){
            rep(j, 0, m){
                cin>>a[i][j];
                if(a[i][j]) r[i] = c[j] = 0;
            }
        }

        int avail = min(accumulate(r, r+n, 0), accumulate(c, c+m, 0));

        if(avail%2==0){
            cout<<"Vivek\n";
        }
        else{
            cout<<"Ashish\n";
        }

    }

    return 0;
}