// First problem solved on codeforces!!
#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double

int main(){
    int i,n;
    cin>>n;
    int arr[n];
    rep(i,0,n) cin>>arr[i];

    int maxLen = 1, len = 1;
    rep(i,1,n){
        if(arr[i]>=arr[i-1])
            len++;
        else{
            maxLen = max(len, maxLen);
            len = 1;
        }
    }
    maxLen = max(maxLen, len);
    cout<<maxLen<<endl;
    return 0;
}