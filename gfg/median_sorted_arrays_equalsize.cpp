#include<iostream>
using namespace std;

float getMedian(int arr[], int n){
    if(n&1)
        return arr[n/2];
    else
        return (arr[n/2-1]+arr[n/2])/2;
}

float medianSorted(int a[], int b[], int n){

    if(n==2)
        return  ( max(a[0],b[0]) + min(a[1],b[1]) )/2.0;

    int median1  = getMedian(a,n);
    int median2 = getMedian(b,n);

    if(median1<median2){
        if(n&1)
            return medianSorted(a+n/2,b,n/2+1);
        else
            return medianSorted(a+n/2-1,b,n/2+1);
    }
    else{
        if(n&1)
            return medianSorted(b+n/2,a,n/2+1);
        else
            return medianSorted(b+n/2-1,a,n/2+1);
    }
}

// Driver code 
int main() 
{ 
    int ar1[] = {1, 2, 3, 6}; 
    int ar2[] = {4, 6, 8, 10}; 
    int n1 = sizeof(ar1) /  
             sizeof(ar1[0]); 
    int n2 = sizeof(ar2) /  
             sizeof(ar2[0]); 
    if (n1 == n2) 
        cout << "Median is "
             << medianSorted(ar1, ar2, n1); 
    else
        cout << "Doesn't work for arrays " 
             << "of unequal size"; 
    return 0; 
} 
