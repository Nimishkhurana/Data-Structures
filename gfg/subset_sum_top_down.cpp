// Code Not working -- Logic Correct

#include<bits/stdc++.h>
using namespace std;


bool subsetSum(int set[],int **dp,int n, int sum){
    if(sum==0){
         dp[n][sum] = true;
        return true;
    }
        
    if((n==0 && sum!=0)){
        dp[n][sum] = false;
        return false;
    }
        
    
    if(dp[n][sum]!=-1)
        return dp[n][sum];

    if(set[n-1]>sum)
        dp[n][sum] = subsetSum(set,dp,n-1,sum);
    else
         dp[n][sum] = subsetSum(set,dp,n-1,sum) || subsetSum(set,dp,n-1,sum-set[n-1]);
    return dp[n][sum];
    // return subsetSum(set,dp,n-1,sum) || subsetSum(set,dp,n-1,sum-set[n]);
}

int main(){
    int t,n,sum;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sum;
        int set[n];
        for(int i=0;i<n;i++) cin>>set[i];

        int **dp = new int*[n+1];
        for(int i=0;i<sum;i++){
            dp[i] = new int[sum+1];

            memset(dp,-1,sum*sizeof(int));
        }

        if(subsetSum(set,dp,n,sum))
            cout<<"True\n";
        else
            cout<<"False\n"<<endl;

    }

}