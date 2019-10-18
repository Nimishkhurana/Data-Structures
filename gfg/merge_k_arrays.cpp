#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    int i;
    int j;

};

class MinHeap{
    node *harr;
    int size;

    void swap(node*,node*);
    int parent(int i) { return (i-1)/2; } 
    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    

    public:
        MinHeap(node[],int);
        void minHeapify(int);
        node getMin();
        int deleteMin();
        void heapSort();
        void replaceMin(node);
        
};

MinHeap::MinHeap(node arr[],int n){
    harr = arr;
    size = n;

    int i = (size - 1)/2; 
    while (i >= 0) 
    { 
        minHeapify(i); 
        i--; 
    } 
}


void MinHeap::swap(node *x,node *y){
    node temp = *x;
    *x = *y;
    *y = temp;
}


void MinHeap::minHeapify(int i){
    if(size==0) return ;

    int smallest = i;
    int l = left(i),r=right(i);
    if(l<size && harr[i].value>harr[l].value) smallest=l;
    if(r<size && harr[smallest].value>harr[r].value) smallest=r;

    if(i!=smallest){
        swap(&harr[i],&harr[smallest]);
        minHeapify(smallest);
    }
}

node MinHeap::getMin(){
    return harr[0];
}

int MinHeap::deleteMin(){
    if(size==0) return INT_MIN;
    node root;
    if(size>1){
        root=harr[0];
        harr[0]=harr[size-1];
        minHeapify(0);
    }
    size--;

    return root.value;
}

void MinHeap::replaceMin(node x){
    // Move current root to end 
        swap(&harr[0], &x); 
  
        // call min heapify on the reduced heap 
        minHeapify(0); 
}

void MinHeap::heapSort(){
    for (int i=size-1; i>=0; i--) 
    { 
        replaceMin(harr[i]);
    } 
}

int *mergeKArrays( int k,int arr[][3])
{
    node* harr = new node[k];
    int *output = new int[k*k];

    for (int i = 0; i < k; i++) 
    { 
        harr[i].value = arr[i][0]; // Store the first element 
        harr[i].i = i;  // index of array 
        harr[i].j = 1;  // Index of next element to be stored from array 
    } 
    MinHeap hp(harr, k);

    for(int i=0;i<k*k;i++){
        node root = hp.getMin();
        output[i]=root.value;

        if(root.j<k) {
            root.value = arr[root.i][root.j];
            root.j++;
        }
        else root.value = INT_MAX;

        hp.replaceMin(root);
    }
    return output;

}

void printArray(int arr[], int size) 
{ 
   for (int i=0; i < size; i++) 
       cout << arr[i] << " "; 
} 

int main() 
{  
    int arr[][3] =  {{2, 6, 12}, 
                     {1, 9, 20}, 
                     {23, 34, 90}}; 
    int k = sizeof(arr)/sizeof(arr[0]); 
  
    int *output = mergeKArrays(k,arr); 
  
    cout << "Merged array is " << endl; 
    printArray(output, k*k); 
  
    return 0; 
} 




