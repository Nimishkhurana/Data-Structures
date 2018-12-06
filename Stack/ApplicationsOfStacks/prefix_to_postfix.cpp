#include<iostream>
#include<string>
using namespace std;

const int size = 10;

class StackArray{
    string s[size];
    int top;
public:
    StackArray();
    void push(string data);
    string pop();
    string peek();
    string prefix_to_postfix(string );
};

StackArray::StackArray(){
    top = -1;
}

void StackArray::push(string data){
    if(top == size-1)
        cout<<"Stack Overflow\n";
    else{
        top++;
        s[top] = data;
        cout<<data<<" pushed to stack\n";
    }

}

string StackArray::pop(){
    if(top == -1){
        cout<<"Stack empty\n";
        return "  ";
    }
    else{
        string temp = s[top];
        top--;
        cout<<temp<<" popped from stack\n";
        return temp;
    }

}

string StackArray::peek(){
    if(top == -1){
        cout<<"Stack empty\n";
        return "  ";
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


string StackArray:: prefix_to_postfix(string pre_exp) {

  int length = pre_exp.size();

  for (int i = length - 1; i >= 0; i--) {

    if (isOperator(pre_exp[i])) {
      string op1 = pop();
      string op2 = pop();

      string temp = op1 + op2 + pre_exp[i];

      push(temp);
    }

    else {
        push(string(1, pre_exp[i]));
    }
  }
  return pop();
}


 int main() {
  int c;
  StackArray s;
  string pre_exp;
  do{
    cout<<"1.Prefix to postfix\n0.Exit\n";
    cin>>c;
    if(c){
      cout<<"Enter string in prefix: ";
      cin>>ws;
      getline(cin,pre_exp);
      cout << "Postfix : " << s.prefix_to_postfix(pre_exp)<<endl;

    }
  }while(c);

}

