#include<deque>
#include<iostream>
using namespace std;

int maxElementEverySubarray(int arr[], int n, int k){
    deque<int> dq(k);

    int i;
    for(i=0;i<k;i++){
        while(!dq.empty() && arr[dq.back()]<=arr[i])
            dq.pop_back();
        dq.push_back(i);
        
    }
    for(;i<n;i++){
        cout<<arr[dq.front()]<<" ";
        
        while(!dq.empty() && dq.front()+k<=i){
            // cout<<arr[dq.front()];
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()]<=arr[i])
            dq.pop_back();
            
        dq.push_back(i);
    }
    cout<<arr[dq.front()];
}

// Driver program to test above functions 
int main() 
{ 
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    maxElementEverySubarray(arr, n, k); 
    return 0; 
} 