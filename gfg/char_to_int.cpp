#include<bits/stdc++.h>
using namespace std;

int main(){

    //CHAR TO INT

    // Convert alphabet to digit such as 'a'->0,'b'->1....
    char a= 'c';
    cout<<a-'a'<<endl;

    // Convert char digit to int digit i.e. '1'->1,'2'-2...
    char b='1'; 
    cout<<b-'0'<<endl;

    //INT TO CHAR

    // Convert digit to alphabet i.e 0->'a',1->'b'...
    int c = 1;  
    cout<<(char)(c+'a')<<endl;

    // Convert digit to char digit i.e. 1->'1',2->'2'...
    int d = 1;
    cout<<(char)(d +'0')<<endl;

    int f = 3;
    int e = f>>1;
    cout<<e<<endl;

    char chh = 'a';
    cout<<(int)chh;

}