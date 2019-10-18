#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int coins[],int n, int V){
    int dp[n+1][V+1];
    // sort(coins,coins+n);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=V;j++){
            
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=INT_MAX;
            else{
                if(coins[i-1]<=j and dp[i][j-coins[i-1]]!=INT_MAX)
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                else
                    dp[i][j] = dp[i-1][j];
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    return dp[n][V]!=INT_MAX?dp[n][V]:-1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,V;
        cin>>V>>n;

        int coins[n];
        for(int i=0;i<n;i++) cin>>coins[i];

        cout<<minimumCoins(coins,n,V)<<endl;
    }
}