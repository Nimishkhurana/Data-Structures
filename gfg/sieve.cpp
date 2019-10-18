#include<iostream>
#include<string.h>
using namespace std;

const int MAX = 1e6;
bool prime[MAX+1];


void sieve(){
    memset(prime, true, sizeof(prime)); 
    prime[0]=false,prime[1]=false;

    for(int i=2;i*i<MAX;i++){
        if(prime[i]){
            for(int j=i*i;j<MAX;j+=i)
                prime[j]=false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    sieve();
    string ans = prime[n]?"Yes":"No";
    cout<<ans;
}