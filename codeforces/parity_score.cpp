#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

// <------------------------------------------------------------------------------------------------->

int n;
vector<int> arr;
vector< vector<vector<vector<int> > > > dp;

int parity(int i){
    return arr[i]%2;
}

int parityDiff(int i, int prevParity, int odds, int evens){

    if(i==n)
        return 0;
    
    if(dp[i][prevParity][odds][evens] != INT_MAX)
        return dp[i][prevParity][odds][evens];
    
    int j;
    if(arr[i] == -1){
        rep(j,0,2){
            if((!odds && j==1) || (!evens && j==0))
                continue;
            dp[i][prevParity][odds][evens] = min(dp[i][prevParity][odds][evens], parityDiff(i+1,j,odds-j,evens-(1-j)) + (prevParity==j?0:1));    
        }
    }
    else 
        dp[i][prevParity][odds][evens] = parityDiff(i+1, arr[i], odds,evens) + (prevParity==arr[i]?0:1);
    
    // cout<<i<<" "<<dp[prevParity][odds][evens]<<endl;

    return dp[i][prevParity][odds][evens];
}

int main(){
    
    cin>>n;
    
    arr.resize(n,0);
   
    int evens = n/2;
    int odds = n - evens;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==0)
            arr[i] = -1;
        else{
            arr[i] %= 2;
            if(arr[i]) odds--;
            else evens--;
        }
    }
     dp.resize(n, vector< vector<vector<int> > >(2,vector<vector<int> >(odds+1,vector<int>(evens+1,INT_MAX))));
        
    cout<<min(parityDiff(0,0,odds,evens), parityDiff(0,1,odds,evens));
}