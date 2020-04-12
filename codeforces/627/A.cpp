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
        int arr[n];
        int i;
        bool flag = true;
        rep(i,0,n){
            cin>>arr[i];
            if(i>0){
                if((arr[i] - arr[i-1])%2!=0)
                    flag = false;
            }
        } 

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}