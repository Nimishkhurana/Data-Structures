#include<iostream>
#include<cmath>
using namespace std;

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void reverseInGroups(int arr[], int n,int k){
   for(int i=0;i<n;i+=k){
       int left = i;
       int right = min(i+k-1,n-1);

       for(int i=left,j=right;i<=j;i++,j--)
            swap(&arr[i],&arr[j]);
   }
   
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        reverseInGroups(arr,n,k);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
}