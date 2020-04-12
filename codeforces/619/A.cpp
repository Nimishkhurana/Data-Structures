#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;

        int i,n = (int)a.length();
        rep(i,0,n){
            if(a[i]==c[i] || b[i]==c[i])
                continue;
            break;
        }
        if(i==n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}