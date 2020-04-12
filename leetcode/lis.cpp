#include<bits/stdc++.h>
using namespace std;

int findUpper(int tail[], int size, int x){
    int l = 0,r = size;

    while(l<r){
        int mid = l + (r - l)/2;

        if(tail[mid]<x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int lis(int arr[], int n){
    int tails[n];
    memset(tails,0,sizeof(tails));
    tails[0] = arr[0];
    int size = 1;
    
    for(int i=1;i<n;i++){
        int u = findUpper(tails,size,arr[i]);
        // cout<<u<<" ";
        tails[u] = arr[i];  
        if(u==size) size++;
    }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<tails[i]<<" ";
    // cout<<endl;
    return size;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<lis(arr,n);
}