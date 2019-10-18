#include<iostream>
using namespace std;

// Not printing ...some bug

void printSpiralMatrix(int arr[4][4],int li,int lj,int m, int n){
    if(li>=m || lj>=n) return;

    // for(int i=li;i<m;i++){
    //     for(int j=lj;j<n;j++)
    //         cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }

    // top row
    for(int j=lj;j<n;j++)
        cout<<arr[li][j]<<" ";
    
    // right column
    for(int i=li;i<m;i--)
        cout<<arr[i][n-1]<<" ";

    // bottom row
    if(li != m-1)
        for(int j=n-2;j>=lj;j--)
            cout<<arr[m-1][j]<<" ";
    
    // left column
    if(lj != n-1)
        for(int i=m-2;i>=li;i--)
            cout<<arr[i][lj]<<" ";

    printSpiralMatrix(arr,li+1,lj+1,m-1,n-1);
}

int main(){
    // int t;
    // cin>>t;
    // while(t--){
    //     int m,n;
    //     cin>>m>>n;
    //     int **arr = new int*[m];
    //     for(int i=0;i<m;i++)
    //         arr[i] = new int[n];
        
    //     for(int i=0;i<m;i++)
    //         for(int j=0;j<n;j++)
    //             cin>>arr[i][j];
        
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++)
    //             cout<<arr[i][j]<<" ";
    //         cout<<endl;
    //     }

        int a[4][4] = { { 1, 2, 3, 4 }, 
                    { 5, 6, 7, 8 }, 
                    { 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16 } }; 
            
        
        printSpiralMatrix(a,0,0,4,4);
        cout<<endl;
    
    
}