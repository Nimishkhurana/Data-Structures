#include<iostream>
using namespace std;

int exponentMod(int a, int b, int c){
    if(a==0)
        return 0;
    if(b==0) 
        return 1;

    long y;

    if(b%2==0){
        y = exponentMod(a,b/2,c);
        y = (y*y)%c;
       
    }
    else{
         y = a%c;
         y = (y* exponentMod(a,b-1,c) %c)%c;
        
    }
    return (int)((y+c)%c);
}

int main(){
    int a,b,c;
    cin>>a;
    cin>> b;
    cin>> c;
    cout<<exponentMod(a,b,c);

}