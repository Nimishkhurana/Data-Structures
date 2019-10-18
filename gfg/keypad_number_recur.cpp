#include<iostream>
using namespace std;

int ioffset[] = {0,-1,0,0,1};
int joffset[] = {0,0,-1,1,0};

bool isSafe(int i, int j){
    if((i>=0 && i<3 && j>=0 && j<3) || (i==3 && j==1))
        return true;
    return false;
}

int dfs(int i,int j,int N){
    if(!isSafe(i,j))
        return 0;
    if(N<=1)
        return N;

    int count=0;

    for(int move=0;move<5;move++){
        int r = i+ioffset[move];
        int c = j+joffset[move];

        count += dfs(r,c,N-1);
    }

    return count;

}

int maxNumbers(int N){
    
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(isSafe(i,j)){
                ans+=dfs(i,j,N);
            }
        }
    }
    return ans;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<maxNumbers(n)<<endl;
    }
}