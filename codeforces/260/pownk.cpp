#include<bits/stdc++.h>
#include <iomanip>
#include<map>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

const int MOD = 5;
int powBE(int x, int e){
    // Calculates x^e using Binary Exponentiation
    int res = 1;
    while(e){
        if(e&1)
            res = (res*x)%MOD;
        x = (x*x)%MOD;
        e/=2;
        
    }
    return res;
}

int fastPow(int x, string e){
    // Calculates x^e when e is very large(string) using Fast Exponentiation
    int len = e.length();

    int res = 1, currBase = x;
    for(int i=len-1;i>=0;i--){
        res = (res * powBE(currBase,e[i] - '0'))%MOD;
        currBase = powBE(currBase,10);
    }
    return res;
}

int main(){
    string e;
    cin>>e;

    cout<< (fastPow(1,e) + fastPow(2,e) + fastPow(3,e) + fastPow(4,e))%MOD;

}