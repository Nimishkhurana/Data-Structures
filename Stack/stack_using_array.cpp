#include<iostream>
#include<string>
using namespace std;

const int size = 10;

class StackArray
{
    int s[size];
    int top;
public:
    StackArray();
    void push(int data=0,bool flag=false);
    int pop();
    void peek();
    void balance_parenthesis();
};
StackArray::StackArray()
{
    top = -1;
}

void StackArray::push(int data,bool flag )
{
    if(!flag){
        cout<<"Enter data to push: ";
        cin>>data;
    }
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        s[top] = data;
        cout<<data<<" pushed to stack\n";
    }

}

int StackArray::pop()
{
    if(top == -1)
        cout<<"Stack empty\n";
    else{
        int temp = s[top];
        top--;
        cout<<temp<<" popped from stack\n";
        return temp;
    }

}

void StackArray::peek()
{
    if(top == -1)
        cout<<"Stack empty\n";
    else
        cout<<"Top element = "<<s[top]<<endl;
}

void StackArray:: balance_parenthesis()
{
    string p;
    bool flag = true;
    cout<<"Enter string of parenthesis:-\n";
    cin>>ws;
    getline(cin,p);
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='(' || p[i]=='{' || p[i]=='[')
            push(p[i],true);
        else if(p[i]==')' || p[i]=='}' || p[i]==']'){
            if (pop()!=p[i]){
                flag = false;
                break;
            }
        }
    }
    if(flag && top!=-1)
        cout<<"Balanced parenthesis\n";
    else
        cout<<"Unbalanced parenthesis\n";

}

int main()
{
    int c,popped_element;
    StackArray S;
    StackArray S2;
    do{
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Check parenthesis\n0.Exit\n\nEnter your choice: ";
        cin>>c;
        switch(c){
    case 1:
        S.push();
        break;
    case 2:
        popped_element = S.pop();
        break;
    case 3:
        S.peek();
        break;
    case 4:
        S2.balance_parenthesis();
        break;
    case 0:
        break;
    default:
        cout<<"Invalid input\n";

    }
}while(c);
}
