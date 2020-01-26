// NOT AC. Gives WA.

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int

#define MOD 1000000007

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        if(!n || !m){
            cout<<0<<endl;
            continue;
        }

        ll dp[2][n+1];
        memset(dp,0,sizeof(dp));

        // dp[0][i] is number of seq. of length i with first 2 digits different
        // dp[1][i] is number of seq. of length i with first 2 digits same

        dp[0][1] = m%MOD;

        for(ll i=2;i<=n;i++){
            dp[0][i] = ( ((m-1)*dp[0][i-1])%MOD + ((m-1)*dp[1][i-1])%MOD + MOD)%MOD;
            dp[1][i] = dp[0][i-1]%MOD;
        }

        ll ans = (dp[0][n]%MOD + dp[1][n]%MOD + MOD)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}