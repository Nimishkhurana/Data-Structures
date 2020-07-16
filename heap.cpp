#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    int *harr;
    int size;

    void swap(int*,int*);
    int parent(int i) { return (i-1)/2; } 
    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    void replaceMin(int);

    public:
        MinHeap(int[],int);
        void minHeapify(int);
        int getMin();
        int deleteMin();
        void heapSort();
};

MinHeap::MinHeap(int arr[],int n){
    harr = arr;
    size = n;

    int i = (size - 1)/2; 
    while (i >= 0) 
    { 
        minHeapify(i); 
        i--; 
    } 
}


void MinHeap::swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void MinHeap::minHeapify(int i){
    if(size==0) return;

    int smallest = i;
    int l = left(i),r=right(i);
    if(l<size && harr[i]>harr[l]) smallest=l;
    if(r<size && harr[smallest]>harr[r]) smallest=r;

    if(i!=smallest){
        swap(&harr[i],&harr[smallest]);
        minHeapify(smallest);
    }
}

int MinHeap::getMin(){
    if(size==0) return INT_MIN;
    return harr[0];
}

int MinHeap::deleteMin(){
    if(size==0) return INT_MIN;
    int root;
    if(size>1){
        root=harr[0];
        harr[0]=harr[size-1];
        minHeapify(0);
    }
    size--;

    return root;
}

void MinHeap::replaceMin(int x){
    // Move current root to end 
        swap(&harr[0], &x); 
  
        // call max heapify on the reduced heap 
        minHeapify(0); 
}

void MinHeap::heapSort(){
    for (int i=size-1; i>=0; i--) 
    { 
        replaceMin(harr[i]);
    } 
    // for(int i=0;i<5;i++) cout<<harr[i]<<" ";
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    MinHeap mh(arr,6);
    mh.heapSort();
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
}




