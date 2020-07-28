#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[33], prefix[33];
void f() {
    dp[0] = dp[1] = 0;
    cerr<<dp[0]<<" "<<dp[1]<<" ";
    for(int i = 2; i < 33; i++) {
        for(int j = 0; j < i; j++) {
            if(j == i-2) 
                dp[i] += (1<<j);
            else 
                dp[i] += dp[j];;
        }
        prefix[i] = prefix[i-1] + dp[i];
        cerr<<dp[i]<<" ";
    }
    cerr<<"\n";
}

bool get(ll x, int b) {
    if(x & (1<<b)) 
        return 1;
    else 
        return 0;
}

ll count(ll x) {
    // Returns count of magical numbers <= x
    ll cnt = 0, lastSet = false, firstSet = -1;
    for(int msb = 32; msb >= 0; msb--) {
        
        if(get(x, msb) && !(~firstSet)) {
            firstSet = msb;
            cnt += prefix[msb];
        }
    }
    for(int msb = 0; msb <= firstSet; msb++) {
        cerr<<cnt<<" ";
        if((get(x, msb) && !lastSet) || (!get(x, msb) && lastSet)) {
            lastSet = true;
            cnt -= dp[msb];
        }
    }
    return cnt;
}


// ll solve(ll l, ll r, ll k) {
    
// }

int main() {
    int T;
    cin>>T;
    f();
    while(T--) {
        // ll l, r, k;
        // cin>>l>>r>>k;
        ll x;
        cin>>x;
        cout<<count(x)<<"\n";
        // solve(l, r, k);
    }
    
}