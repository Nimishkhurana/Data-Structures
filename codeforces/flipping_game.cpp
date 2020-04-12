#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long

int main(){
    int n;
    cin>>n;
    int num,count=0;
    int maxSum = -10, currSum = 0;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num){
            count++;
            num = -1;
        }
        else
            num = 1;
        
        currSum = max(currSum + num, num);
        maxSum = max(maxSum, currSum);
    }

    cout<<maxSum + count<<endl;
    return 0;
}