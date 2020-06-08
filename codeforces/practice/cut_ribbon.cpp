#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double

int n,a,b,c;
vector<int> dp;
int go(int n){
    if(n==0)
        return 0;
    if(n<0)
        return INT_MIN;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = max(max(go(n-a), go(n-b)), go(n-c)) + 1;
}

int main(){
    int n;
    cin>>n>>a>>b>>c;
    dp.resize(n+1,-1);
    cout<<go(n)<<endl;
}