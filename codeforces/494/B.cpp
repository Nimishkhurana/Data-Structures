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

string get(int a, int b, int x, char c1, char c2){
    string ans;
    ans += string(b-((x+1+2-1)/2-1), c2);
    ans += string(a-((x+1)/2-1), c1);

    int i;
    rep(i, 0, x-1){
        if(i&1) ans.pb(c1);
        else ans.pb(c2);
    }
    return ans;
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int a, b, x;
    cin>>a>>b>>x;
    string ans;
    if(a < b)
        ans = get(a, b, x, '0', '1');
    else 
        ans = get(b, a, x, '1', '0');

    cout<<ans<<"\n";
   
    return 0;
}