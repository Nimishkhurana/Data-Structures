#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d,i;
        cin>>n>>d;
        int a[n];
        rep(i,0,n) cin>>a[i];

        int cost,borrow;
        int j = 1;
        while(d>0 && j<n){
            if(a[j]!=0){
                borrow = min(a[j], (int)d/j);
                if(borrow == 0)
                    break;
                d -= borrow*j;
                a[0] += borrow;
                // cout<<d<<" "<<borrow<<"  ";
            }
            j++;
        }
        cout<<a[0]<<endl;
    }

}