#include<iostream>
#include<string.h>
using namespace std;


bool isInterleaved(string s1, string s2, string s3){
    int m = s1.length();
    int n = s2.length();

    bool dp[m+1][n+1];

    memset(dp,false,sizeof(dp));

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            int s3_ind = i+j-1;

            // Both s1 and s2 empty, then s3 is interleaving
            if(i==0 && j==0)
                dp[i][j] = true;

            // s1 empty
            else if(i==0)
                dp[i][j] = (s3[s3_ind] == s2[j-1]) && dp[i][j-1];
            
            // s2 empty
            else if(j==0)
                dp[i][j] = (s3[s3_ind] == s1[i-1]) && dp[i-1][j];
            

            else
                dp[i][j] = ((s3[s3_ind] == s2[j-1]) && dp[i][j-1]) || ((s3[s3_ind] == s1[i-1]) && dp[i-1][j]);
            
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }

    return dp[m][n];
}

int main() 
{ 
    cout<<isInterleaved("XXY", "XXZ", "XXZXXXY")<<endl; 
    cout<<isInterleaved("XY", "WZ", "WZXY")<<endl; 
    cout<<isInterleaved("XY", "X", "XXY")<<endl; 
    cout<<isInterleaved("YX", "X", "XXY")<<endl; 
    cout<<isInterleaved("XXY", "XXZ", "XXXXZY")<<endl; 
    return 0; 
} 