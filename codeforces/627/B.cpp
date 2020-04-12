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
        int i,n;
        cin>>n;
        int a[n], freq[n+1] = {0};
        vector<int> ind[n+1];
        rep(i,0,n){
            cin>>a[i];
            freq[a[i]]++;
            ind[a[i]].pb(i);
        }

        bool flag = false;
        rep(i,1,n+1){
            if(freq[i]>2){
                flag = true;
                break;
            }      
        } 

        int j;
        if(!flag){
            rep(i,1,n+1){
                if(freq[i]==2){
                    if(ind[i][1] - ind[i][0] > 1)
                        flag = true;
                }
            }
        }

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}