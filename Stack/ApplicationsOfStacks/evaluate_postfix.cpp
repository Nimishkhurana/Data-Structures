#include<iostream>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

const int size = 10;

class StackArray{
    int s[size];
    int top;
public:
    StackArray();
    void push(int data);
    int pop();
    int peek();
    void evaluate_postfix();
};

StackArray::StackArray(){
    top = -1;
}

void StackArray::push(int data){
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        s[top] = data;
        cout<<data<<" pushed to stack\n";
    }

}

int StackArray::pop(){
    if(top == -1){
        cout<<"Stack empty\n";
        return ' ';
    }
    else{
        int temp = s[top];
        top--;
        cout<<temp<<" popped from stack\n";
        return temp;
    }

}

int StackArray::peek(){
    if(top == -1){
        cout<<"Stack empty\n";
        return -1;
    }
    else{
        cout<<"Top element = "<<s[top]<<endl;
        return s[top];
    }
}

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

int calc(int x,int y,char op)
{
    int res =0;
    switch (op)
    {
    case '+':
      res = x + y;
      break;
    case '-':
      res = x - y;
      break;
    case '*':
      res = x * y;
      break;
    case '^':
        res = pow(x,y);
        break;
    case '/':
        res = x/y;
        break;
    }
    return res;
}


void StackArray::evaluate_postfix()
{
    string postfix;
    cout<<"\nEnter postfix expression to evaluate: ";
    cin>>ws;
    getline(cin,postfix);
    cout<<"\n\n";
    cout<<"Procedure:-\n";
    for(int i = 0;i<20;i++) cout<<'=';
    cout<<endl;
    for(int i=0;i<postfix.length();i++){
        char temp = postfix[i];

        if(temp == ' ') continue;


        else if(isOperator(temp))
        {
            int op2 = pop();
            int op1 = pop();

            int res = calc(op1,op2,temp);
            push(res);
        }
        else if(isdigit(postfix[i])){
            int num=0;
            while(isdigit(postfix[i])){
                num = num*10 + (int)(postfix[i]-'0');
                i++;
            }
            i--;
            push(num);
        }
    }
    int result = pop();
    for(int i = 0;i<20;i++) cout<<'=';
    cout<<"\n\nResult = "<<result<<"\n\n\n";

}
int main(){
    int c;
    int popped_element;
    StackArray S,S3;
    StackArray S2;
    do{
        cout<<"1.Push\n2.Pop\n3.Peek\n4.Evaluate Postfix\n0.Exit\n\nEnter your choice: ";
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
        S.evaluate_postfix();
    case 0:
        break;
    default:
        cout<<"Invalid input\n";
        }
    }while(c);
}

