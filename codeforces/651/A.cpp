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

const int mxn = 1e6+1;
int spf[mxn];
    
void sieve(){
    for(int i = 0; i< mxn; i++) spf[i] = i;

    for(int i=2;i*i<mxn;i++){
        if(spf[i]==i){
            for(int j=i*i;j<mxn;j+=i)
                spf[j]= min(spf[j], i);
        }
    }
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    sieve();
    while(T--){
        int i, j, n;
        cin>>n;
        int ans = 1;
        rep(i, 2, n+1){
            ans = max(ans, i/spf[i]);
        }
        cout<<ans<<"\n";
    }
   
    return 0;
}