#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &ans){
    for(auto x: ans){
        cout<<x<<" ";
    }
        
    cout<<endl;
}

void printSubsetsRecur(int set[],bool **dp, int n, int sum,vector<int> &ans){

    if (n == 0 && sum != 0 && dp[0][sum]) 
    { 
        ans.push_back(set[n]); 
        display(ans); 
        return; 
    } 

    if(n==0 && sum==0){
        display(ans);
        return;
    }

    if(dp[n-1][sum]){
        vector<int>t = ans;
        printSubsetsRecur(set,dp,n-1,sum,t);
    }
    if(sum>=set[n] && dp[n-1][sum-set[n]]){
        ans.push_back(set[n]);
        printSubsetsRecur(set,dp,n-1,sum-set[n],ans);
    }
}

int subsetSum(int set[],int n, int sum){
    bool **dp = new bool*[n];

    for(int i=0;i<=n;i++){
        dp[i] = new bool[sum+1];
    }

    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    
    if (set[0] <= sum) 
       dp[0][set[0]] = true; 
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(set[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }

    if(dp[n-1][sum]){
        vector<int>ans;
        printSubsetsRecur(set,dp,n-1,sum,ans);
    }
    return dp[n-1][sum];
}



int main(){
    int t,n,sum;
    cin>>t;
    while(t--){
        cin>>n;
        int set[n];
        for(int i=0;i<n;i++) cin>>set[i];
        cin>>sum;

        if(subsetSum(set,n,sum))
            cout<<"True\n";
        else
            cout<<"False\n"<<endl;
    }
}