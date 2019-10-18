#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int arr[n],dp[n][n];
	    for(int i=0;i<n;i++) cin>>arr[i];

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i-j<2)
        //             dp[i][j]=max(arr[i],arr[j]);
        //     }
        // }

        // for(int gap=2;gap<n;gap++){
        //     for(int i=0;i<n-gap;i++){
        //         int j=i+gap;
        //         int x = dp[i+2][j];
        //         int y = dp[i+1][j-1];
        //         int z = dp[i][j-2];
        //         dp[i][j] = max(arr[i]+min(x,y),arr[j]+min(y,z));
        //     }
        // }
        //Better way to fill matrix diagonally 
        for(int gap=0;gap<n;gap++){
            for(int i=0, j=gap;j<n;i++,j++){
                
                int x = ((i + 2) <= j) ? dp[i+2][j] : 0;
                int y = ((i + 1) <= (j - 1)) ? dp[i+1][j-1] :0;
                int z = (i <= (j - 2)) ? dp[i][j-2] :0;
                dp[i][j] = max(arr[i]+min(x,y),arr[j]+min(y,z));
            }
        }

        cout<<dp[0][n-1]<<endl;
	    
	    
	}
}

