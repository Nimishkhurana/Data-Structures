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
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int i, j, n;
        cin>>n;
        int prev_p = 0, prev_c = 0, p, c;
        bool flag = 1;
        rep(i, 0, n){
            cin>>p>>c;
            if(c < prev_c || p < prev_p || (c - prev_c > p - prev_p))
                flag = false;
            prev_c = c;
            prev_p = p;
        } 

        if(flag)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}