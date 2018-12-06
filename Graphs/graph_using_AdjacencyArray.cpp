#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of vertices in graph: ";
    cin>>n;
    int a[n][n];
    cout<<"Enter adjacency matrix for graph:-\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Adjacency Matrix:-\n";
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]!=0)
                    cout<<"\nVertex "<<i<<" is connected to Vertex "<<j;


}


