#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int m;
        cin>>m;

        sort(arr,arr+n,greater<int>());
        int i=m-1,j=m;
        for(;j<n;j++,i--){
            arr[i]+=arr[j];
        }
        int maxx = INT_MIN;
        for(int i=0;i<m;i++){
            maxx = max(maxx,arr[i]);
        }
        cout<<maxx<<endl;

    }
}