#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
    int t = *x;
    *x = *y;
    *y = t;
}
void sortArray(int arr[], int n){
    int l = 0,m=0,r=n-1;
    while(m<=r){
        if(arr[m]==0){
            swap(&arr[l],&arr[m]);
            l++;
            m++;
        }
        else if(arr[m]==2){
            swap(&arr[m],&arr[r]);
            r--;
        }
        else
            m++;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        sortArray(arr,n);

        for(int i=0;i<n;i++)
            cout<<arr[i];
        cout<<endl;
    }
}