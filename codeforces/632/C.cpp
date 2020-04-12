#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<int,int>
#define umapl map<ll, ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}

umapl prefix;
int main(){
    fast 
    int i, n;
    cin>>n;
    ll a[n+1];
    rep(i, 1, n+1) cin>>a[i];

    
    prefix[0] = 1;

    ll sum = 0, sub = 0, ans = 0;
    rep(i, 1, n+1){
        sum += a[i];

        if(prefix.count(sum))
            sub = max(sub, prefix[sum]);

        prefix[sum] = i + 1;

        ans += (i - sub);
        // cout<<ans<<" ";
    }

    cout<<ans<<"\n";
    return 0;
}