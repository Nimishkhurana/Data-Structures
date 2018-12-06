#include<iostream>
#include<string>
using namespace std;

const int size = 10;

class StackArray{
    int s[size];
    int top;
public:
    StackArray();
    void push(char data);
    char pop();
    char peek();
    void balance_parenthesis();
    void infix_to_postfix();
};

StackArray::StackArray(){
    top = -1;
}

void StackArray::push(char data){
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        s[top] = data;
        cout<<data<<" pushed to stack\n";
    }

}

char StackArray::pop(){
    if(top == -1){
        cout<<"Stack empty\n";
        return ' ';
    }
    else{
        char temp = s[top];
        top--;
        cout<<temp<<" popped from stack\n";
        return temp;
    }

}

char StackArray::peek(){
    if(top == -1){
        cout<<"Stack empty\n";
        return ' ';
    }
    else{
        cout<<"Top element = "<<s[top]<<endl;
        return s[top];
    }
}

void StackArray:: balance_parenthesis(){
    string p;
    bool flag = true;
    cout<<"Enter string of parenthesis:-\n";
    cin>>ws;
    getline(cin,p);
    for(int i=0;i<p.length();i++)
    {
        if(p[i]=='(' || p[i]=='{' || p[i]=='[')
            push(p[i]);
        else if(p[i]==')'){
            if(pop()!='('){
                flag=false;
                break;
               }
        }
        else if(p[i]=='}'){
            if(pop()!='{'){
                flag=false;
                break;
               }
        }
         else if(p[i]==']'){
            if(pop()!='['){
                flag=false;
                break;
            }
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag && top==-1)
        cout<<"\n\nBalanced parenthesis\n";
    else
        cout<<"\n\nUnbalanced parenthesis\n";
}

int getOperatorValue(char ch){
    switch(ch){
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void StackArray:: infix_to_postfix(){
    string infix,postfix="";
    char ch,temp;
    cout<<"Enter expression in infix:-\n";
    cin>>ws;
    getline(cin,infix);
    for(int i=0;i<infix.length();i++){
        temp = infix[i];
        if(temp =='(')
            push(temp);
        else if(temp == '-' || temp == '+' || temp == '*' || temp == '/' || temp == '^' || temp == '%'){
            while(getOperatorValue(peek()) >= getOperatorValue(temp)){
                postfix+=pop();
            }
                push(temp);
        }
        else if(temp == ')'){
           while((ch = pop())!='('){
                    postfix+=ch;
                 }
        }
        else
            postfix += temp;
    }
    while((ch=pop())!=' '){
        postfix+=ch;
    }
    cout<<"Postfix expression = "<<postfix<<endl;
}


int main(){
    int c;
    char popped_element;
    StackArray S,S3;
    StackArray S2;
    do{
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Check parenthesis\n5.Infix to Postfix\n0.Exit\n\nEnter your choice: ";
        cin>>c;
        switch(c){
    case 1:
        S.push('a');
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
    case 5:
        S3.infix_to_postfix();
        break;
    case 0:
        break;
    default:
        cout<<"Invalid input\n";
        }
    }while(c);
}
