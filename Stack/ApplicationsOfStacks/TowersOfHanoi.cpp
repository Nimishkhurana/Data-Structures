#include<iostream>
using namespace std;


void towerOfHanoi(int n,char source,char destination,int aux){

    if(n == 1){
        cout<<"Move disk from tower "<<source<<" to "<<destination<<endl;
        return;
    }
    towerOfHanoi(n-1,source,aux,destination);
    towerOfHanoi(1,source,destination,aux);
    towerOfHanoi(n-1,aux,destination,source);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    towerOfHanoi(n,'S','D','A');
}

