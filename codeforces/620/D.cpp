#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define pb push_back

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int mx[n], mn[n],i,j;
        bool vis[n+1] = {0};

        int curr = n, last = 0;
        rep(i,0,n){
            if(i==n-1 || s[i] == '>'){
                rrep(j,i,last){
                    mn[j] = curr--;
                    // cout<<j<<" ";
                }
                    
                last = i + 1;
            }
        }
        // cout<<endl;
        curr = 1, last = 0;
        rep(i,0,n){
            if(i==n-1 || s[i] == '<'){
                rrep(j,i,last){
                    mx[j] = curr++;
                    // cout<<j<<" ";
                }    
                last = i + 1;
            }
        }
        // cout<<endl;
        rep(i,0,n)
            cout<<mn[i]<<" ";
        cout<<endl;

        rep(i,0,n)
            cout<<mx[i]<<" ";
        cout<<endl;
    }
    return 0;
}