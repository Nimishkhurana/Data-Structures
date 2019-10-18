#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

int main(){
    int t,n;
    string s;
	cin>>t;
	while(t--){
	    cin>>s;
        n = s.length();
	    int dp[n][n];

        memset(dp,0,sizeof(dp));
	   
        //Better way to fill matrix diagonally 
        for(int gap=1;gap<n;gap++){
            for(int i=0, j=gap;j<n;i++,j++){
                
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i][j-1],dp[i+1][j])+1;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<"\n";

        // }

        cout<<dp[0][n-1]<<endl;
	    
	    
	}
}

