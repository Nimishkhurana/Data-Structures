#include <bits/stdc++.h>
using namespace std;

int fun(int arr[],int n,int k){
    sort(arr,arr+n);
    int upper = upper_bound(arr, arr+n, k) - arr; 
    for(int i=upper;i<n-1;i++){
        arr[i+1] = arr[i+1] - (arr[i]-k);
        arr[i]=k;
    }
    // arr[n-1] = 
    int sum=0;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        sum+=arr[i];
    }
    cout<<endl;
        
    return sum;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    int sum = fun(arr,n,k);
	    cout<<sum<<endl;
	}
	return 0;
}
