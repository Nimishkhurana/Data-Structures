#include<iostream>
using namespace std;

struct node{
    long pk;
    string name;
    node* link;
};

class Hashing{
    int n;
    node** rows;

    int countDigit(long);
    node * getNode(long, string);
    void insertEnd(int,node *);
    void traverseList(node* );
    int generateHash(long);
    void deleteFromList(int,long);

public:
    Hashing();
    void addRecord();
    void displayTable();
    void deleteRecord();

};

Hashing::Hashing(){
    n =10;
    rows = new node*[n];
    for(int i=0;i<n;i++){
        rows[i] = getNode(0,"");
    }
}

node* Hashing:: getNode(long pk_,string n){
    node *temp = new node;
    temp->pk = pk_;
    temp->name = n;
    temp->link = NULL;
    return temp;
}

void Hashing:: insertEnd(int Hash,node *N){
    int counter =2;
    node *temp = rows[Hash];
    if(temp == NULL){
        cout<<"ERROR\n";
        return;
    }

    while(temp->link){
        temp = temp->link;
        counter++;
    }
    temp->link = N;
    cout<<"Record "<<counter<<" of Hash "<<Hash<<" inserted\n";


}
int Hashing::countDigit(long n)
{
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}


void Hashing:: addRecord(){
    int key,Hash;
    string n;
    cout<<"Enter 5-digit Primary Key: ";
    cin>>key;
    if(countDigit(key)!=5){
        cout<<"Please enter 5-digit key\n";
        return;
    }
    cout<<"Enter name : ";
    cin>>n;
    Hash = generateHash(key);

    if(rows[Hash]->pk ==0){
        rows[Hash]->pk = key;
        rows[Hash]->name = n;
        cout<<"Record 1 of Hash "<<Hash<<" inserted\n";
        return;
    }
    else{
        node *temp = getNode(key,n);
        insertEnd(Hash,temp);
    }
}

int Hashing::generateHash(long pk_){
    return pk_%10;
}



void Hashing:: displayTable(){
    cout<<"List representation of Table:-\n\n";
    for(int i=0;i<n;i++){
        cout<<"HASH "<<i<<": ";

        traverseList(rows[i]);
        cout<<endl;
    }
}

void Hashing:: traverseList(node* head){
    if(head==NULL){
        cout<<"ERROR\n";
        return;
    }
    node *temp = head;
    while(temp){
        if(temp->pk!=0)
            cout<<temp->pk<<"|"<<temp->name<<" -> ";
        temp = temp->link;
    }
}

void Hashing::deleteRecord(){
    int h_;
    long pk_;
    cout<<"Enter primary key to delete: ";
    cin>>pk_;
    h_ = pk_%10;
    if(rows[h_]->pk == pk_){
        rows[h_]->pk = 0;
        rows[h_]->name = "";

    }
    else{
        deleteFromList(h_,pk_);
    }
    cout<<"Record deleted\n";
}
void Hashing:: deleteFromList(int h_,long pk_){

     node *save = rows[h_];
     node *temp = save->link;
    while(temp){
        if(temp->pk == pk_){
            save->link = temp->link;
            delete temp;
            return;
        }
        temp = temp->link;
    }
}

int main(){
    int ch;
    Hashing hashing;
    do{
        cout<<"\n1.Add Record\n2.Display  List of Hashing Table\n3.Delete Record\n0.Exit\n\nEnter your choice: ";
        cin>>ch;
        switch(ch){
    case 1:
        hashing.addRecord();
        break;
    case 2:
        hashing.displayTable();
        break;
    case 3:
        hashing.deleteRecord();
        break;

        }
    }while(ch!=0);
}

