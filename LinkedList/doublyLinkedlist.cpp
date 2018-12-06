#include<iostream>
using namespace std;

struct node{
    int info;
    node *next;
    node *prev;
}*head = NULL,*tail = NULL;
                                        // prototypes of functions
node* getNode(int);
void traverseListFromHead();
void traverseListFromTail();
node* searchNodeFromHead(int );
node* searchNodeFromTail(int);
void insertBeg(int);
void insertEnd(int);
void insertLoc(int ,node *ahead = NULL,bool flag = false);
void deleteNode(int );
node * findAheadForInsertion(int);

struct node* getNode(int data){            //function to get a new node
    node *N = new node;
    N->info = data;
    N->next = NULL;
    N->prev = NULL;
    return N;
}

void traverseListFromHead(){             //function to traverse list from head
    node *start = head;

    while(start){
        cout<<start->info<<"->";
        start = start->next;
    }
    cout<<"\n\n";
}
void traverseListFromTail(){             //function to traverse list from tail
    node *start = tail;

    while(start){
        cout<<start->info<<"->";
        start = start->prev;
    }
    cout<<"\n\n";
}

node* searchNodeFromHead(int data){     //function to search a node from head
    bool flag = false;
    node *start = head,*loc=NULL;
    int ind=0;
    while(start){
        if(start->info == data){
             cout<<data<<" found at index "<<ind<<endl;
             flag = true;
             loc = start;
            }
        ind++;
        start = start->next;
    }
    if(!flag)
        cout<<"Data not found\n";
    return loc;
}

node* searchNodeFromTail(int data){
    bool flag = false;
    node *loc = NULL;
    node *start = tail;
    int ind=0;
    while(start){
        if(start->info == data){
             cout<<data<<" found at index "<<ind<<endl;
             flag = true;
             loc = start;
            }
        ind++;
        start = start->prev;
    }
    if(!flag)
        cout<<"Data not found\n";
    return loc;
}

void insertBeg(int data){
    node *N = getNode(data);
    if(head == NULL)
        head = tail= N;
    else{
        N->next = head;
        head->prev = N;
        head = N;
    }
    cout<<"Node inserted at beginning\n";

}

void insertEnd(int data){
    node *N = getNode(data);
    if(tail == NULL)
        head = tail = N;
    else{
        N->prev = tail;
        tail->next = N;
        tail = N;
    }
    cout<<"Node inserted at end\n";
}

void insertLoc(int data,node *ahead,bool flag){
    node *N = getNode(data);
    if(flag == false)
        ahead = findAheadForInsertion(data);
    if(head == NULL)
        insertBeg(data);
    else if(ahead == NULL)
    {
        tail->next = N;
    }
    else{
        N->next = ahead;
        N->prev = ahead->prev;
        ahead->prev->next = N;
        ahead->prev = N;
        cout<<"Node inserted at appropriate location\n";
       }
}

node * findAheadForInsertion(int data){
    node *ptr = NULL;
    if(head == NULL )
        return ptr;

    ptr = head;
    while(ptr){
        if(ptr->info > data)
            return ptr;
        ptr = ptr->next;
    }
    return ptr;

}

void deleteNode(int data){
    node *loc = NULL;
    loc = searchNodeFromHead(data);
    if(loc==NULL){
        cout<<"Node not found in list\n";
        return;
    }
    else if(loc==head && head->next==NULL)
    {
        head = tail = NULL;
        delete head;
        cout<<"List emptied\n";
    }
    else if(loc == head){
        head = head->next;
        head->prev = NULL;
        delete loc;
        cout<<"Front Node deleted \n";
    }
    else if(loc == tail){
        tail = tail->prev;
        tail->next = NULL;
        delete loc;
        cout<<"Last Node deleted \n";
    }
    else{
        loc->prev->next = loc->next;
        loc->next->prev = loc->prev;
        delete loc;
        cout<<"Node deleted \n";
    }
}



int main()
{
    node *N;
    int c,data;
    do{
        cout<<"Enter your choice :-\n\n1.View list from front\n2.View list from back\n3.Insert at beginning\n4.Insert at end\n5.Insert anywhere in sorted list\n6.Delete Node\n7.Search from beginning\n8.Search from end\n0.Exit\n";
        cin>>c;
        switch(c){
            case 1:
                traverseListFromHead();
                break;
            case 2:
                traverseListFromTail();
                break;
            case 3:
                cout<<"Enter data to insert at beginning: ";
                cin>>data;
                insertBeg(data);
                break;
            case 4:
                cout<<"Enter data to insert at the end: ";
                cin>>data;
                insertEnd(data);
                break;
            case 5:
                cout<<"Enter data to insert in sorted list: ";
                cin>>data;
                insertLoc(data);
                break;
            case 6:
                cout<<"Enter data to delete: ";
                cin>>data;
                deleteNode(data);
                break;
            case 7:
                cout<<"Enter data to search from head: ";
                cin>>data;
                searchNodeFromHead(data);
                break;
            case 8:
                cout<<"Enter data to search from tail: ";
                cin>>data;
                searchNodeFromTail(data);
                break;
            case 0:
                break;
            default:
                cout<<"Invalid input\n";
                break;
            }
    }while(c!=0);
}

