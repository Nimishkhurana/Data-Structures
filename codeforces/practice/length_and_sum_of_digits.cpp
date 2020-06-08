#include<bits/stdc++.h>
#include <iomanip>
#include<map>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

bool can(int s, int m){
    if(s<0) return false;

    return s <= m*9;
}

int main(){
    int m,s;
    cin>>m>>s;
    int s_ = s;
    string minNum = "", maxNum = "";
    // int minNum, maxNum;
    for(int i=0;i<m;i++){
        for(int digit=0;digit<10;digit++){
            if((i || digit || (m==1)) && can(s-digit,m-i-1)){
                minNum.push_back(digit + '0');
                s -= digit;
                break;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int digit=9;digit>=0;digit--){
            if((i || digit || (m==1)) && can(s_-digit,m-i-1)){
                maxNum.push_back(digit + '0');
                s_ -= digit;
                break;
            }
        }
    }
    // cout<<minNum.length()<<" ";
    if(minNum.length()==m)
        cout<<minNum<<" ";
    else
        cout<<"-1"<<" ";
    
    if((int)maxNum.length()==m)
        cout<<maxNum<<" ";
    else
        cout<<"-1"<<endl;
    
}