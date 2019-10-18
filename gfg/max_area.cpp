
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
//Position this line where user code will be pasted.

/*This is a function problem.You only need to complete the function given below*/
/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   g[][]: 2D matrix from input
*   vis[][]: visited array
*/

vector<pair<int,int>> offset{{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{-1,-1},{1,-1}};

bool isSafe(int i, int j){
    if(i>=0 && j>=0 && i<SIZE && j<SIZE)
        return true;
    return false;
}

void dfs(int i, int j, int g[SIZE][SIZE], bool vis[SIZE][SIZE], int &count){
    
    if(!isSafe(i,j) || vis[i][j] || g[i][j]!=1) return;
    
    vis[i][j] = true;
    count++;
    
    for(int i=0;i<8;i++)
        dfs(i+offset[i].first, j+offset[j].second,g,vis,count);
    
}
int findAreaUtil(int n, int m, int g[SIZE][SIZE], bool vis[SIZE][SIZE]){
    int area=0,max_area=0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(g[i][j]==1){
                area = 0;
                dfs(i,j,g,vis,area);
                if(area>max_area) max_area=area;
                
            }
        }
    }
    return max_area;
    
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        
        int g[SIZE][SIZE];
        bool vis[SIZE][SIZE];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>g[i][j];
        }
        
        memset(vis, 0, sizeof(vis));
        
        cout << findAreaUtil(n, m, g, vis) << endl;
      
    }
      
	return 0;
}
