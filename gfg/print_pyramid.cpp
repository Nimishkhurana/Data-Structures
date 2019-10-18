#include<iostream>
using namespace std;

void print_asterisk(int n){
    if(n==0) return;

    cout<<"* ";

    print_asterisk(n-1);
}

void print_space(int n){
    if(n==0) return;

    cout<<"  ";

    print_space(n-1);
}

void printPyramid(int n, int num){
    if(n<=0)
        return;
    
    print_space(n);
    print_asterisk(2*(num - n) + 1);
    cout<<endl;

    printPyramid(n-1,num);
}

int main(){
    printPyramid(5,5);
}

