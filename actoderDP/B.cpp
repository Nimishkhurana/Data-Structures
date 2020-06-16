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
#define INF 1000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, k;
    cin>>n>>k;
    int i, j;
    int h[n];
    rep(i, 0, n) cin>>h[i];

    vector<int> dp;
    dp.push_back(0);
    for(int i = 1; i < n; i++){
        int cur = INF, j = i-1;
        for(auto it = dp.rbegin(); it != dp.rend(); it++){
            cur = min(cur, *it + abs(h[i] - h[j--]));
        }

        if(dp.size()==k)
            dp.erase(dp.begin());
        dp.push_back(cur);
    }
    cout<<dp.back();
   
    return 0;
}