#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double

int n,a,b,c;
vector<int> dp;
int go(int n){
    for(int i=1;i<=n;i++)
        dp[i] = max(max((i-a>=0)?dp[i-a]:INT_MIN, (i-b>=0)?dp[i-b]:INT_MIN),(i-c>=0)?dp[i-c]:INT_MIN) + 1;
    return dp[n];
}

int main(){
    int n;
    cin>>n>>a>>b>>c;
    dp.resize(n+1,INT_MIN);
    dp[0] = 0;
    cout<<go(n)<<endl;
}