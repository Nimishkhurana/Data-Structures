#include<iostream>
#include<cstring>
using namespace std;


bool isPalindrome(char* s){
    int n = strlen(s);
    char* l = s;
    char* r = s+n-1;

    while(l<=r){
        if(*l!=*r)
            return false;
        l++;
        r--;
    }
    return true;
}

int mimimumAppends(char* s){
    int n = strlen(s);  
    char *i = s;
    int count=0;

    while(n--){
        cout<<i<<" ";
        if(isPalindrome(i))
            return count;
        count++;
        i++;
    }

    return count;
}

int main(){
    cout<<"Enter length of string: ";
    int n;
    cin>>n;
    char *s = new char[n+1];

    cin>>s;

    cout<<mimimumAppends(s)<<endl;
}

