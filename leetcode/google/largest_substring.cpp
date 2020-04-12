#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int curr_max = INT_MIN;
    int start;
    for(int i=0;i<n-k;i++){
        if(arr[i]>=arr[i+1]){
            start = i;
        }
        if(arr[i]>curr_max){
            start = i;
            curr_max = arr[i];
        }
    }
}