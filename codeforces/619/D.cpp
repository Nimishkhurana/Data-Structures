#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define mk make_pair
#define pb push_back

vector<pair<int,string>> res, temp;

int main() {
    int n, m, k, i, j;
    cin>>n>>m>>k;
    int mx = 2*((m-1)*n + (n-1)*m);
    if(k > mx) {
        cout<<"NO\n";
        exit(0);
    }

    rep(i,1,n+1) {
        res.pb(mk(m-1, "R"));

        if(i<n) {
            res.pb(mk(m-1,"DUL"));
            res.pb(mk(1, "D"));
        }   
        else { 
            res.pb(mk(m-1, "L"));
            res.pb(mk(n-1, "U"));
        }
    }

    int len, f, curr, rem;
    string s;
    while(mx > k) {
        f = res.back().first;
        s = res.back().second;
        len = (int)s.length();
        res.pop_back();
        curr = f * len;

        mx -= curr;
        if(mx >= k)
            continue;
        
        curr = k - mx;
        f = curr/len;
        if(f)
            res.pb(mk(f,s));
        
        rem = curr%len;
        if(rem){
            s.resize(rem);
            res.pb(mk(1,s));
        }
        mx = k; 
    }

    cout<<"YES\n";
    // temp = res;
    // res.clear();
    // for(pair<int,string> p: temp)
    //     if(p.first)
    //         res.pb(p);
    
    cout<<res.size()<<endl;
    for(pair<int,string> p: res)
        cout<<p.first<<" "<<p.second<<endl;


    return 0;
}