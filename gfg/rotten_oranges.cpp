#include<bits/stdc++.h>
using namespace std;

const int ioffset[] = {-1,0,0,1};
const int joffset[] = {0,-1,1,0};

bool isComplete(int **arr,int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        if(arr[i][j]==1)
            return false;
    }
    return true;
}

bool isSafe(int i, int j, int m, int n){
    if(i<0 || i>=m || j<0 || j>=n) return false;
    return true;
}

void rotNeighbours(int **arr,int i,int j, int m,int n,queue<pair<int,int>> &q){
    for(int k=0;k<4;k++){
        int ti = i+ioffset[k];
        int tj = j+joffset[k];
        if(isSafe(ti,tj,m,n) && arr[ti][tj]==1){
            arr[ti][tj] = 2;
            q.push({ti,tj});
        }
        

    }
}

int countTime(int **arr, int m, int n){
    queue<pair<int,int>> q;
    int time=0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(arr[i][j]==2)
                q.push({i,j});
    while(!q.empty()){
        time++;
        int s = q.size();
        while(s--){
            pair<int,int> t = q.front();
            q.pop();
            rotNeighbours(arr,t.first,t.second,m,n,q);
        }
        if(isComplete(arr,m,n)){
            cout<<"returning "<<time;
            return time;
        } 
    }
    return -1;
}

int main(){
    int t,r,c;
    cin>>t;
    while(t--){
        cin>>r>>c;
        int **arr = new int*[r];
        for(int i=0;i<r;i++)
            arr[i] = new int[c];
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>arr[i][j];
        
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         cout<<arr[i][j]<<" ";
        
        cout<<countTime(arr,r,c)<<endl;   

    }
}
