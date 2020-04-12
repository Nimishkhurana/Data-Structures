#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int i,mx = INT_MIN,mn = INT_MAX;
        

        rep(i,0,n){
           cin>>a[i];
        }

        rep(i,0,n){
            if(i<n && a[i+1] == -1 && a[i] != -1)
                mn = min(mn, a[i]), mx = max(mx, a[i]);
            else if(i>0 && a[i-1] == -1 && a[i] != -1)
                mn = min(mn, a[i]), mx = max(mx, a[i]);
        }

        int res1 = INT_MIN, res2 = (mn + mx)/2;

        rep(i,0,n){
            if(a[i] == -1)
                a[i] = res2;
            if(i)
                res1 = max(res1, abs(a[i] - a[i-1]));
        }
        cout<<res1<<" "<<res2<<endl;
    }
}