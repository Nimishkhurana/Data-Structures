#include<iostream>
#include<ctime>
using namespace std;

void Merge(int[],int,int,int);
void mergeSort(int a[],int p,int r)
{
   if(p<r)
    {
        int q = (p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }
}

void Merge(int a[],int p,int q,int r){

    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i] = a[p+i];
    for(int j=0;j<n2;j++)
        R[j] = a[q+j +1];

    int i=0,j=0,k;
    for(k=p; i<n1 && j<n2; k++){
        if(L[i]<R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
    }
    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = R[j];
        j++;
        k++;
    }

}

int main(){
    int a[100001];
    for(int i=100000;i>=0;i--){
        a[i] = i;
    }
    cout<<"START\n";
    clock_t start= clock();
    mergeSort(a,0,100001);
    cout<<"DONE\n";
    clock_t finish = clock();
    float elapsed = (float)(finish - start)/CLOCKS_PER_SEC;
    cout << "Elapsed time: " << elapsed<< " s\n";



}
