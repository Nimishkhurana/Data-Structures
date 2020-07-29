//Author: nimishkhurana //WA
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

const int mxn = 1e6;
int parent[mxn], size[mxn];

void initialize() {
    for(int i = 0; i < mxn; i++) {
        parent[i] = i;
    }
}

int getParent(int u) {
    int p = parent[u];
    if(p == u) {
        return u;
    }
    return parent[u] = getParent(p);
}

bool merge(int u, int v) {
    int pu = getParent(u), pv = getParent(v);
    if(pu == pv) {
        return false;
    }

    if(size[pu] > size[pv]) {
        parent[pv] = pu;
    }
    else {
        parent[pu] = pv;
    }

    return true;
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
        int n, q;
        cin>>n;
        initialize();
        if(n >= mxn) {
            assert(0);
        }
        rep(i, 0, n) 
            cin>>size[i];
        cin>>q;
        rep(i, 0, q) {
            int type;
            cin>>type;
            if(type) {
                int u;
                cin>>u;
                u--;
                cout<<getParent(u)+1<<"\n";
            }
            else {
                int u, v;
                cin>>u>>v;
                u--, v--;
                if(!merge(u, v)) {
                    cout<<"Invalid query!\n";
                }
            }
        }
    }
   
    return 0;
}