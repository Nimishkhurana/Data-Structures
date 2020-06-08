#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

int main(){
    int n,q;
    cin>>n>>q;
    bool maze[3][n+1];
    memset(maze,false,sizeof(maze));
    int i,x,y,blockedPairs=0;
    rep(i,0,q){
        cin>>x>>y;
        maze[x][y] = !maze[x][y];
        if((maze[x][y]) && (maze[3-x][y] || y?maze[3-x][y-1]:false || y<n?maze[3-x][y+1]:false)){
            cout<<"No\n";
            blockedPairs++;
        }
            
        else{
            blockedPairs--;
            if(!blockedPairs)
                cout<<"Yes\n";

        }
            
    }
    return 0;

}