#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    fast 
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"-1\n";
            continue;
        }

        string res = "2";
        int i,s = 0;

        rep(i,0,n-1){
            res+="3";
        }

        
        cout<<res<<"\n";
    }
    return 0;
}