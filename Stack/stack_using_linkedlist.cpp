#include<iostream>
using namespace std;

struct node{
    char info;
    node *link;
}*top = NULL;

node* getNode(char);
void push(char );
node* pop();
node* peek();

node* getNode(char data){
    node *N = new node();
    N->info = data;
    N->link = NULL;
    return N;
}


void push(char data){
    node *N = getNode(data);
    if(top == NULL)
        top = N;
    else{
        N->link = top;
        top = N;
    }
    cout<<"Node pushed\n";
}

node* pop(){
    if(top==NULL){
       cout<<"Stack Underflow\n";
        return NULL;
       }
    else{
         node *temp = top;
        if(top->link==NULL)
            top = NULL;
        else
            top = top->link;

        delete top;
        return temp;
    }
}

node* peek()
{
        if(top==NULL){
        cout<<"Stack Underflow\n";
        return NULL;
       }
    else
        return top;
}

int main()
{
    push('a');
    push('c');
    cout<<peek()->info<<endl;
    pop();
    cout<<peek()->info;
}
