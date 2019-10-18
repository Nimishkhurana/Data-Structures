#include<iostream>
using namespace std;

int left(int i){ return 2*i+1;}
int right(int i){ return 2*i+2;}

int swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void maxHeapify(int arr[],int i, int n){
    if(n==0) return;

    int l = left(i);
    int r = right(r);

    int largest = i;

    if(l<n && arr[i]<arr[l]) largest=l;
    if(r<n && arr[i]<arr[r]) largest=r;

    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,largest,n);
    }
}

int extractMax(int arr[], int n){
    if(n==0) return INT_MIN;

    int root = arr[0];
    arr[0] = arr[n-1];
    maxHeapify(arr,0,n);

    return root;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int i=n/2-1;

    while(i>=0){
        maxHeapify(arr,i,n);
    }
}