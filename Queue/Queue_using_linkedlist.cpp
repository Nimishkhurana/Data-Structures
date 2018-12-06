#include<iostream>
using namespace std;

struct node{
    char info;
    node *link;
}*Front,*Rear = NULL;

node* getNode(char);
void Qinsert(char );
char Qdelete();
void peek();

node* getNode(char data){
    node *N = new node();
    N->info = data;
    N->link = NULL;
    return N;
}


void Qinsert(char data){
    node *N = getNode(data);
    if(Front == NULL)
        Front = Rear = N;
    else{
        Rear->link = N;
        Rear = N;
    }
    cout<<"Node inserted\n";
}

char Qdelete(){
    char data;
    if(Front==NULL){
       cout<<"Queue Underflow\n";
       return ' ';
       }
    else{
         node *temp = Front;
         data = Front->info;
        if(Front == Rear)
            Front = Rear = NULL;
        else
            Front = Front->link;
        delete temp;
        return data;
    }
}

void peek()
{
        if(Front==NULL){
        cout<<"Queue Empty\n";
       }
    else
        cout<<"Front: "<<Front->info;
}

int main()
{

 int c;
 char data,deleted_data;
 do{
    cout<<"\n1.Insert in Queue\n2.Delete from Queue\n3.View Front node data\n0.Exit\n\nEnter your choice: ";
 cin>>c;
 switch(c){
case 1:
    cout<<"Enter data to insert: ";
    cin>>data;
    Qinsert(data);
    break;
case 2:
    deleted_data = Qdelete();
    if(deleted_data!=' ')
        cout<<deleted_data<<" deleted\n";
    break;
case 3:
    peek();
    break;
case 0:
    break;
default:
    cout<<"Invalid Choice\n";
    }
 }while(c);
}
