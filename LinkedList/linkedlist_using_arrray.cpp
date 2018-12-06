#include<iostream>
using namespace std;

struct Node{
int info;
int link;
}node[10];
int head=-1,avail=0;

int getNode(int);
void traverseList();
void search_node(int );
void insertBeg(int );
void insertAnywhere(int,int prev = -1,bool flag = false );
void freeNode(int );
int findPrevInsertion(int );
void find_locP_loc_delete(int ,int *,int *);



int getNode(int data)
{
    cout<<"Head = "<<head<<" and avail = "<<avail<<endl;
    int p = avail;
    avail = node[avail].link;
    node[p].info = data;
    node[p].link = -1;
    return p;
}

void traverseList()
{
    int p = head;
    while(p!=-1)
    {
        cout<<node[p].info<<"->";
        p = node[p].link;
    }
    cout<<"\nHead = "<<head<<"\nAvail = "<<avail<<endl;
}

void search_node(int data)
{
    int p = head;
    bool flag = false;
    while(p!= -1)
    {
        if(node[p].info == data)
        {
            cout<<data<<" found at index "<<p<<endl;
            flag = true;
        }
        p = node[p].link;
    }
    if(!flag)
        cout<<data<<" not found in the list\n";
}

void insertBeg(int data)
{
    if(avail == -1)
        cout<<"Overflow\n";
    else if(head == -1)
    {
        int p = getNode(data);
        head = p;
        cout<<"First node of list made\n";
    }

    else
    {
        int p = getNode(data);
        cout<<"p = "<<p<<endl;
        node[p].link = head;
        head = p;
        cout<<"Node inserted at beginning\n";
    }

}
void insertAnywhere(int data,int prev2 ,bool flag)
{
    int prev;
    if(!flag)
        prev = findPrevInsertion(data);
    else
        prev = prev2;
    if(prev == -1)
        insertBeg(data);
    else
    {
        cout<<"Prev = "<<prev;
        int p = getNode(data);
        node[p].link = node[prev].link;
        node[prev].link = p;
        cout<<"Node inserted at appropriate location\n";
    }
}

int findPrevInsertion(int data)
{
    int prev = -1,ptr = -1;
    if(head == -1 or data < node[head].info){
        return prev;
    }
    prev = head;
    ptr = node[prev].link;
    while(ptr!= -1)
    {
        if(node[ptr].info > data)
            return prev;
        prev = ptr;
        ptr = node[ptr].link;
    }
    return prev;

}

void freeNode(int data)
{
    int locP = -1,loc = -1;
    find_locP_loc_delete(data,&locP,&loc);
    if(locP == -1 && loc == -1)
    {
        cout<<"List empty\n";
        return;
    }
    else if(locP == -1)
    {
        head = node[head].link;
        cout<<"Front Node deleted \n";
    }
    else
    {
        node[locP].link = node[loc].link;
        cout<<"Node deleted\n";
    }
    node[loc].link = avail;
    avail = loc;
}


void find_locP_loc_delete(int data,int *locP,int *loc)
{
    if(head == -1)
        return;
    else if(node[head].info == data)
    {
        *loc = head;
        return;
    }
    else
    {
        *locP = head;
        *loc = node[*locP].link;
        while(*loc !=-1)
        {
            if(node[*loc].info == data)
                return;

            *locP = *loc;
            *loc = node[*loc].link;
        }
    }
}

void init_avail_list()
{
     for(int i=0;i<9;i++)
        node[i].link = i+1;
    node[9].link = 5;
    node[4].link = -1;
}
void init_avail_list_random()
{
    node[0].link = 3;
    node[1].link = 5;
    node[2].link = 6;
    node[3].link = 1;
    node[4].link = 9;
    node[5].link = 2;
    node[6].link = 4;
    node[7].link = 8;
    node[8].link = -1;
    node[9].link = 7;
}

void showAvail()
{
     for(int i=0;i<10;i++)
        cout<<node[i].link<<" ";
}

int main()
{
    init_avail_list_random();


    cout<<endl;
    int c,data;
    do{
        cout<<"Enter your choice :-\n\n1.Insert at beginning\n2.Insert anywhere\n3.Delete Node\n4.Display list\n5.Search\n0.Exit\n";
    cin>>c;
    switch(c)
    {
        case 1:
            cout<<"Enter info to insert: ";
            cin>>data;
            insertBeg(data);
            break;
        case 2:
            showAvail();
            cout<<"Enter info to insert: ";
            cin>>data;
            insertAnywhere(data);
            break;
        case 3:
            cout<<"Enter data to delete: ";
            cin>>data;
            freeNode(data);
            break;
        case 4:
            traverseList();
            break;
        case 5:
            cout<<"Enter data to search: ";
            cin>>data;
            search_node(data);
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input\n";
            break;
    }
}while(c!=0);

    }
