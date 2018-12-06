#include<iostream>
using namespace std;

const int Size = 10;

class circularQueue{
    int a[Size];
    int Front;
    int Rear;
public:
    void initializeCircularQueue()
    {
        Front = Rear = -1;
    }
    void QInsert(int data);
    int QDelete();
    void peak();
};

void circularQueue::QInsert(int data){

    if(Front == Rear+1 || (Rear == Size-1 && Front == 0)){
        cout<<"Can't insert....Queue Overflow!!\n";
        return;
    }
    if(Front == -1){
        Front = Rear = 0;
    }
    else if(Rear == Size-1)
        Rear = 0;
    else
        Rear++;
    a[Rear] = data;
    cout<<data <<" inserted successfully at index "<<Rear<<endl;
    }

int circularQueue::QDelete(){

    if(Front == -1){
        cout<<"Queue Underflow\n";
        return -1;
    }
    int item = a[Front];
    if(Front == Rear){
        initializeCircularQueue();
    }
    else if(Front == Size-1)
        Front = 0;
    else
        Front++;

    cout<<"Front node having data "<<item<<" deleted\n";
    return item;

}

void circularQueue::peak(){
    if(Front!=-1)
        cout<<"Front: "<<a[Front]<<endl;
    else
        cout<<"Queue Empty\n";
}


int main(){
 circularQueue Queue;
 Queue.initializeCircularQueue();

 int c,data,deleted_data;
 do{
    cout<<"\n1.Insert in Queue\n2.Delete from Queue\n3.View front node data\n0.Exit\n\nEnter your choice: ";
 cin>>c;
 switch(c){
case 1:
    cout<<"Enter data to insert: ";
    cin>>data;
    Queue.QInsert(data);
    break;
case 2:
    deleted_data = Queue.QDelete();
    break;
case 3:
    Queue.peak();
    break;
case 0:
    break;
default:
    cout<<"Invalid Choice\n";
    }
 }while(c);
}

