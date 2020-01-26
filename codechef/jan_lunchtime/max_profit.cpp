#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s,p,v;
        int maxProfit = 0, profit;
        while(n--){
            cin>>s>>p>>v;
            profit = (int)(p/(s+1))*v;
            maxProfit = max(maxProfit, profit);
        }
        cout<<maxProfit<<endl;
    }
    return 0;
}