#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int count = 0;

    for(int i=2;i<n;i++){

        while(n%i==0){
            count+=i;
            n/=i;
        }
        if(n<=4 && n>1){
            count+=n;
            break;
        }

    }

    cout<<count<<endl;
}