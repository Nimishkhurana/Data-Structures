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
        int i, j, n;
        cin>>n;
        vector<int> a(n);
        rep(i, 0, n) cin>>a[i];

        i = 0;
        int cnt = 0, start;
        while(i < n) {
            // cerr<<i<<" "<<a[i]<<" "<<" "<<cnt<<"\n";
            if(a[i] != i+1) {
                i++;
                continue;
            }
            start = i;
            while(i < n && a[i] == i+1) i++;
            if(i == n) break;
            if(start == 0) continue;
            cnt += 2;
        }
        // cerr<<cnt<<"\n";
        if(!is_sorted(a.begin(), a.end())) {
            cnt = max(cnt, 1);
        }
        cout<<cnt<<"\n";
    }

   
    return 0;
}