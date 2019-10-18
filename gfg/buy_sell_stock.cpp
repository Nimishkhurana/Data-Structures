#include<iostream>
using namespace std;

int maxDiff(int arr[], int n){
    int minn = arr[0];
    int max_diff = INT_MIN;

    for(int i=0;i<n;i++){
        max_diff = max(max_diff,arr[i]-minn);
        minn = min(minn,arr[i]);
    }
    return max_diff;
}

int main() 
{ 
  int arr[] = {1, 2, 90, 10, 110}; 
  int n = sizeof(arr) / sizeof(arr[0]); 
    
  // Function calling 
  cout << "Maximum difference is " << maxDiff(arr, n); 
  
  return 0; 
} 