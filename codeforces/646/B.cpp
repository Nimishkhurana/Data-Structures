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
        int i, j;
        string s;
        cin>>s;
        int n = s.length();
        if(n < 3){
            cout<<"0\n";
            continue;
        }

        int ones[n], zeroes[n], onesp[n], zeroesp[n];
        rep(i, 0, n){
            if(i){
                ones[i] = ones[i-1];
                zeroes[i] = zeroes[i-1];
            }
            else{
                ones[i] = 0;
                zeroes[i] = 0;
            }
            if(s[i]=='1') ones[i]++;
            else zeroes[i]++;
        }

        rrep(i, n-1, 0){
            if(i<n-1){
                onesp[i] = onesp[i+1];
                zeroesp[i] = zeroesp[i+1];
            }
            else{
                onesp[i] = 0;
                zeroesp[i] = 0;
            }
            if(s[i]=='1') onesp[i]++;
            else zeroesp[i]++;
        }

        int ans = min(min(onesp[0], zeroesp[0]), min(ones[n-1], zeroes[n-1]));
        cerr<<ans<<" ";
        rep(i, 0, n-1){
            ans = min(ans, min(ones[i], zeroes[i]) + min(onesp[i+1], zeroesp[i+1]));
            cerr<<ans<<" ";
        }
        cout<<ans<<"\n";
        cerr<<"\n";
        
    }
    
   
    return 0;
}