#include<iostream>
using namespace std;


void printSpiralMatrix(int **arr,int m, int n){
    
    int li=0,lj=0;

    while(li<m && lj<n){
    
        // top row
        for(int j=lj;j<n;j++){
            cout<<arr[li][j]<<" ";
        }
            
        li++;
          
        // right column
        for(int i=li;i<m;i++)
            cout<<arr[i][n-1]<<" ";
        n--;
       
        // bottom row
        if(li < m){
            for(int j=n-1;j>=lj;j--)
                cout<<arr[m-1][j]<<" ";
            m--;
        }   
       
        // left column
        if(lj < n){
            for(int i=m-1;i>=li;i--)
                cout<<arr[i][lj]<<" ";
            lj++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        int **arr = new int*[m];
        for(int i=0;i<m;i++)
            arr[i] = new int[n];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];

        printSpiralMatrix(arr,m,n);    
        cout<<endl;
        

        }
    
    
}