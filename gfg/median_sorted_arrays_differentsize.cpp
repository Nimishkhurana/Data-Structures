#include<iostream>
using namespace std;

float medianUnequalSizeArrays(int a[], int b[], int n1, int n2){
    if(n1 > n2)
        medianUnequalSizeArrays(b,a,n2,n1);
    
    int low = 0;
    int high = n1;

    while(low<=high){

        int partitionX = (low + high)/2;
        int partitionY = (n1 + n2 + 1)/2 - partitionX;

        int maxLeftX = (partitionX==0)?INT_MIN:a[partitionX-1];
        int minRightX = (partitionX==n1)?INT_MAX:a[partitionX];

        int maxLeftY = (partitionY==0)?INT_MIN:b[partitionY-1];
        int minRightY = (partitionY==n2)?INT_MAX:b[partitionY];

        cout<<endl;
        cout<<"maxLeftX: "<<maxLeftX<<" "<<"minRightX: "<<minRightX<<endl;
        cout<<"maxLeftY: "<<maxLeftY<<" "<<"minRightY: "<<minRightY<<endl;
        
        if(maxLeftX <= minRightY && maxLeftY <= minRightX){
            if((n1+n2)%2!=0)
                return max(maxLeftX,maxLeftY);       
            else
                return ( max(maxLeftX,maxLeftY) + min(minRightX,minRightY) )/2.0;
        }
        else if(maxLeftX > minRightY)
            high = partitionX - 1;
        else 
            low = partitionX + 1;
    }

}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++) cin>>a[i];
    for(int i=0;i<n2;i++) cin>>b[i];

    cout<<endl<<medianUnequalSizeArrays(a,b,n1,n2);

}