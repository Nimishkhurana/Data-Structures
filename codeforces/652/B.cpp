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
        string s;
        cin>>s;
        vector<char> s2;
        int zeroes = 0, ones = 0;
        bool z = 1, o = 0;
        rep(i, 0, n){
            if(s[i]=='1') break;
            zeroes++;
        }
        rrep(i, n-1, 0){
            if(s[i]=='0') break;
            ones++;
        }
        for(auto c: s){
            if(s2.empty() || s2.back() != c) s2.push_back(c);
        }
        cerr<<s2[0]<<"\n";
        string ans;
        ans += string(zeroes, '0');
        if(s2.size() > 2){
            ans += '0';
        }
        else if(s2.size() == 2 && s2[0] == '1'){
            ans = '0';
        }
    
        ans += string(ones, '1');

        cout<<ans<<"\n";
    }
   
    return 0;
}