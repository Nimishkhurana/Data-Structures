#include<bits/stdc++.h>
#define R 3
#define C 3
using namespace std;
 
int minInitialPoints(int points[][C])
{
    int m=R,n=C;
   int dp[m][n];
    dp[m-1][n-1]=points[m-1][n-1]>0? 1:abs(points[m-1][n-1])+1;
    for(int i=m-2;i>=0;i--)
       {
           dp[i][n-1]=max((dp[i+1][n-1]-points[i][n-1]),1);
       }

    for(int i=n-2;i>=0;i--)
           dp[m-1][i]=max((dp[m-1][i+1]-points[m-1][i]),1);
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            int mini=min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]=max((mini-points[i][j]),1);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
    }
    return dp[0][0];
   
}
 
// Driver Program
int main()
{
 
    int points[R][C] = { {1,-300,600},
                         {-5,1,-10},
                         {10,-2,-30}
                    };
    cout << "Minimum Initial Points Required: "
         << minInitialPoints(points);
    return 0;
}