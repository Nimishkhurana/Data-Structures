#include<iostream>
using namespace std;

struct node{
    int info;
    node *link;
}*head = NULL;

node* getNode(int);
void traverseList();
void searchNode(int );
void insertBeg(int );
void insertLoc(int ,node *prev = NULL,bool flag = false);
void deleteNode(int );
node * findPrevForInsertion(int );
void find_locP_loc_for_delete(int ,node **,node **);

node* getNode(int data){    //Function to get a new node
    node *N = new node();
    N->info = data;
    N->link = NULL;
    return N;
}


void traverseList(){        //Function to traverse the linkedlist
    node *temp = head;
    while(temp){
        cout<<temp->info<<"->";
        temp = temp->link;
    }
    cout<<"\n\n";
}

void searchNode(int data){  //Function to search a node with particular data
    node *ptr = head;
    bool flag = false;
    int ind=0;
    while(ptr){
        if(ptr->info == data){cout<<data<<" found at index "<<ind<<endl;
             flag = true;
            }
        ind++;
        ptr = ptr->link;
    }
    if(!flag)
        cout<<"Data not found\n";
}

void insertBeg(int data){       //Function to insert a node at beginning
    node *N = getNode(data);
    if(head == NULL)
        head = N;
    else{
        N->link = head;
        head = N;
    }
    cout<<"Node inserted at beginning\n";

}

void insertLoc(int data,node *prev,bool flag){  //if flag=false:-Function to insert at appropriate location itself in a sorted list
    node *N = getNode(data);                    //flag=true:- Insert after given prev node
    if(flag == false)
        prev = findPrevForInsertion(data);
    if(prev == NULL)
        insertBeg(data);
    else if(prev->link == NULL)
        prev->link = N;
    else{
        N->link = prev->link;
        prev->link = N;
        cout<<"Node inserted at appropriate location\n";
    }
}

node * findPrevForInsertion(int data){  //Utility function to find prev location for inserting node in sorted list
    node *prev =NULL,*ptr=NULL;
    if(head == NULL)
        return prev;
    else if(data < head->info)
        return prev;
    prev = head;
    ptr = prev->link;
    while(ptr){
        if(ptr->info > data)
            return prev;
        prev = ptr;
        ptr = ptr->link;
    }
    return prev;

}

void deleteNode(int data){      //Function to delete a node from list
    node *locP =NULL;
    node *loc = NULL;
    find_locP_loc_for_delete(data,&locP,&loc);
    if(locP==NULL && loc==NULL){
        cout<<"List empty\n";
        return;
    }
    else if(locP == NULL){
        head = head->link;
        cout<<"Front Node deleted \n";
    }
    else{
        locP->link = loc->link;
        cout<<"Node deleted \n";
    }
}

void find_locP_loc_for_delete(int data,node **locP,node **loc){ //Utility function to find loc of node to be deleted and its prev node;
    cout<<"Function called\n";
    if(head == NULL){
        cout<<"List is empty\n";
        *locP = *loc = NULL;
        return;
    }
    else if(head->info == data){
        cout<<"First node\n";
        *locP = NULL;
        *loc = head;
        return;
    }
    else{
        cout<<"Other node\n";
        *locP = head;
        *loc = (*locP)->link;
        while(*loc){
            if((*loc)->info == data)
                return;
            *locP = *loc;
            *loc = (*loc)->link;
        }
        cout<<"Last node\n";
    }
}

int main()
{
    node *N;
    int c,data;
    do{
        cout<<"Enter your choice :-\n\n1.Insert at beginning\n2.Insert anywhere\n3.Delete Node\n4.Display list\n5.Search\n0.Exit\n";
    cin>>c;
    switch(c){
        case 1:
            cout<<"Enter info to insert: ";
            cin>>data;
            insertBeg(data);
            break;
        case 2:
            cout<<"Enter info to insert: ";
            cin>>data;
            insertLoc(data);
            break;
        case 3:
            cout<<"Enter data to delete: ";
            cin>>data;
            deleteNode(data);
            break;
        case 4:
            traverseList();
            break;
        case 5:
            cout<<"Enter data to search: ";
            cin>>data;
            searchNode(data);
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input\n";
            break;
            }
    }while(c!=0);
}
