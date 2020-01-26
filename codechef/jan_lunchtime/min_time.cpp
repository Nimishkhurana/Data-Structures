#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,a,b,c;
        cin>>n>>a>>b>>c;
        long long int f;
        long long int time,minTime = 1e10;
        while(n--){
            cin>>f;
            time = abs(a-f) + abs(b-f) + c;
            minTime = min(minTime, time);
        }
        cout<<minTime<<endl;
    }

    return 0;
}