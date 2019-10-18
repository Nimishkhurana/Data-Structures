#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[],int n, int V){
    int dp[n+1][V+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=V;j++){
            
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else{
                if(coins[i-1]<=j)
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    return dp[n][V];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,V;
        cin>>n;

        int coins[n];
        for(int i=0;i<n;i++) cin>>coins[i];
        cin>>V;

        cout<<coinChange(coins,n,V)<<endl;
    }
}