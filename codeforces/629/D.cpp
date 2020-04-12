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
        int t[n];
        int i;
        rep(i,0,n) cin>>t[i];

        int res[n];
        res[0] = 1;
        int curr = 1, used = 1;
        rep(i,1,n-1){
            if(t[i]==t[i-1])
                res[i] = curr;
            else{
                if(curr==1)
                    res[i] = curr = 2, used = 2;
                else
                    res[i] = curr = 1;
            }
        }

        if(t[n-2]==t[n-1]){
            res[i] = curr;
        }
        else{
            if(curr==1)
                res[n-1] = curr = 2, used = 2;
            else
                res[n-1] = curr = 1;
            
            if(res[n-1] == res[0])
                res[n-1] = 3, used = 3;
        }

        cout<<used<<"\n";
        rep(i,0,n) cout<<res[i]<<" \n"[i==n-1];
    }
    return 0;
}