#include<iostream>
using namespace std;

int getMaxSubarraySumSizeK(int arr[], int n, int k){
    int sum = 0;
    
    int i;
    for(i=0;i<k;i++)
        sum+=arr[i];
    
    int maxSum=sum;
    
    
    for(;i<n;i++){
        cout<<sum<<" ";
        sum = sum+arr[i]-arr[i-k];
        maxSum = max(sum,maxSum);
    }

    cout<<sum<<" ";

    return maxSum;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<getMaxSubarraySumSizeK(arr,n,k)<<endl;
    }
}