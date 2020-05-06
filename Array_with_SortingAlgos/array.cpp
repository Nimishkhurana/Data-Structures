#include<iostream>
#include <ctime>
using namespace std;

class Array{
int a[500000];
int size;

public:
    void getdata();
    void showdata();
    void selectionsort();
    void bubblesort();
    void insertionSort();
    void linearsearch();
    void binarySearch();
    void insertelement();
    void deleteelement();
};

void Array::getdata()
{
    int j=0;
   cout<<"Enter the number of elements :-";
   cin>>size;

  for(int i=size;i>0;i--)
  {a[j] = i;
   j++;}
}

void Array::showdata()
{
    cout<<"Array :-\n";
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Array::selectionsort()
{
    int small,ind;
    for(int i=0;i<size-1;i++)
    {
       small = a[i];
       for(int j = i+1;j<size;j++)
       {
           if(a[j] < small)
             {
                 small = a[j];
                 ind = j;
             }
       }
       int temp = a[i];
       a[i] = small;
       a[ind] = temp;
    }
}
void Array::bubblesort()
{
    int flag;
    for(int i=0;i<size;i++)
    {   flag = 0;
        for(int j=0;j<size-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

void Array::insertionSort()
{
    int temp,j;
    for(int i=1;i<size;i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j] > temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
void Array::linearsearch()
{
    int num,ind = -1;
    cout<<"Enter the element to search: ";
    cin>>num;
    for(int i=0;i<size;i++)
        if(a[i] == num)
           {
             ind = i;
             break;
           }
    if(ind == -1)
        cout<<"Element not found in array\n";
    else
        cout<<"Element "<<num<<" found at index "<<ind<<endl;
}

void Array:: binarySearch()
{
    int key,start=0,finish = size,ind = -1;
    cout<<"Enter the element to search: ";
    cin>>key;
    while(start<=finish)
    {
        int mid = (start + finish)/2;
        if(a[mid] == key)
           {
               ind = mid;
               break;
           }
        else if(a[mid]>key)
            finish = mid-1;
        else
            start = mid+1;
    }
    if(ind != -1)
        cout<<"Number found at index "<<ind<<endl;

    else
        cout<<"Number not found\n";
}

void Array::insertelement()
{
    int ind,num;
    cout<<"Enter the position at which you want to insert element: ";
    cin>>ind;
    cout<<"Enter the element :";
    cin>>num;

    if(size==20)
        cout<<"Array overloaded\n";
    else{
        for(int i=size-1;i>=ind;i--)
            a[i+1] = a[i];
        a[ind] = num;
        size++;
    }
}

void Array::deleteelement()
{
    int ind;
    cout<<"Enter the index to delete element at: ";
    cin>>ind;

    if(ind > size-1)
        cout<<"Index out of size";
    else
    {
        for(int i=ind;i<size;i++)
            a[i] = a[i+1];
        cout<<"Element deleted successfully\n";
        size--;
    }
 }

 int main()
 {
     int i;
     char ch;
     do{
     Array A;
     A.getdata();
    do{
     cout<<"1.Linear Search\n2.Binary Search \n3.Insert\n4.Delete\n5.Display\n6.Bubble Sort\n7.Selection Sort\n8.Insertion Sort\n0.Exit\n\nEnter your choice: ";
     cin>>i;
     time_t time1,time2,time3,time4,time5,time6;

     switch(i)
     {
         case 1:time1 = time(NULL);
                A.linearsearch();
                time2 = time(NULL);
                cout << "Time taken by Linear Search: "
         << time2 - time1 << " seconds" << endl;
                break;
         case 2:time1 = time(NULL);
                A.binarySearch();
                time2 = time(NULL);
                cout << "Time taken by Binary Search: "
         << time2 - time1 << " seconds" << endl;
                break;
         case 3:A.insertelement();
                break;
         case 4:A.deleteelement();
                break;
         case 5:A.showdata();
                break;
         case 6:time1 = time(NULL);
                A.bubblesort();
                time2 = time(NULL);
                cout << "Time taken by Bubble Sort: "
         << time2 - time1 << " seconds" << endl;
         break;
         case 7:time3 = time(NULL);
                A.selectionsort();
                time4 = time(NULL);
                cout << "Time taken by Selection Sort: "
         << time4 - time3 << " seconds" << endl;
         break;
         case 8:time5 = time(NULL);
                A.insertionSort();
                time6 = time(NULL);
                cout << "Time taken by Insertion Sort "
         << time6 - time5 << " seconds" << endl;

         case 0:break;
         default:cout<<"\nInvalid input\n";
     }
     if(i!=0)
     {cout<<"Do you want to operate on same array [y/n]: ";
     cin>>ch;
     }
    }while(ch!='n' && ch!='N' && i!=0);
     }while(i!=0);
 }
