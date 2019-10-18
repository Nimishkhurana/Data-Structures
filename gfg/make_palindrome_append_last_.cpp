#include<iostream>
#include<cstring>
using namespace std;


bool isPalindrome(char* s, int start){
    // cout<<s+start<<" ";
    int l = start;
    int r = strlen(s)-1;
    while(l<=r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }

    return true;
}

int mimimumAppends(char* s){
    int n = strlen(s);  
    int i;
    for(i=0;i<n;i++)
        if(isPalindrome(s,i))
            return i;

}

int main(){
    cout<<"Enter length of string: ";
    int n;
    cin>>n;
    char *s = new char[n+1];

    cin>>s;

    cout<<mimimumAppends(s)<<endl;
}

