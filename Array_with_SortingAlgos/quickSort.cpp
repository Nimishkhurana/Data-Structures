#include<iostream>
using namespace std;

int Partition(int a[],int r,int s){

    int temp = a[s];

    int i=r-1;

    for(int j=r;j<s;j++)
    {
        if(a[j]<=temp)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[s]);
    return i+1;
}

void QuickSort(int a[],int r,int s)
{
    int q;
    if(r<s){
      q = Partition(a,r,s);
      QuickSort(a,r,q-1);
      QuickSort(a,q+1,s);
    }
}

int main()
{
    int a[10];
    cout<<"Enter array:-\n";
    for(int i=0;i<10;i++)
        cin>>a[i];
    QuickSort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<"\t";
}


