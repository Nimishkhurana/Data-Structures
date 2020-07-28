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
    // fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int T;
    cin>>T;
    while(T--){
        int i, j;
        string p = "abacaba";
        string s;
        int len = p.length();
        int n;
        cin>>n;
        cin>>s;
        int cnt1 = 0, cnt2 = 0;
        vector<int> ind;
        for(int i = 0; i < n-len+1; i++) {
            bool bad = 0;
            for(int j = 0; j < len; j++) {
                if(s[i+j] == p[j]) continue;
                bad = 1;
                break;
            }
            if(!bad) {
                cnt1++;
                continue;
            }
            bad = 0;
            for(int j = 0; j < len; j++) {
                if(s[i+j] == p[j] || s[i+j] == '?') continue;
                bad = 1;
                break;
            }
            if(!bad) {
                cnt2++;
                ind.pb(i);
            }
        }
        // cerr<<cnt1<<" "<<cnt2<<"\n";
        if(cnt1 == 1) {
            cout<<"YES\n";
            for(int i = 0; i < n; i++) {
                if(s[i] == '?') cout<<"z";
                else cout<<s[i];
            }
            cout<<"\n";
        }
        else if(cnt1 == 0 && cnt2) {
            string t;
            bool done = 0;
            for(int in: ind) {
                t = s;
                i = 0;
                int cnt3 = 0;
                // cerr<<in<<"   ";
                while(i < n) {
                    // cerr<<i<<" ";
                    if(i < n - len +1 && i == in) {
                        for(int j = 0; j < len; j++) {
                            if(t[i+j] == '?') t[i+j] = p[j]; 
                        }
                        i += len;
                        continue;
                    }
                    else if(t[i] == '?') t[i] = 'z';
                    i++;
                }
                // cout<<"HH";
                for(int i = 0; i < n-len+1; i++) {
                    bool bad = 0;
                    for(int j = 0; j < len; j++) {
                        if(t[i+j] == p[j]) continue;
                        bad = 1;
                        break;
                    }
                    if(!bad) {
                        cnt3++;
                        continue;
                    }
                }
                // cerr<<in<<" "<<cnt3<<" \n";
                if(cnt3 == 1) {
                    cout<<"YES\n";
                    cout<<t<<"\n";
                    done = 1;
                    break;
                }
            }
            if(!done) {
                cout<<"NO\n";
            }  
        }
        else {
            cout<<"NO\n";
        }
    }
   
    return 0;
}