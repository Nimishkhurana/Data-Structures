#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>
#define pb push_back

int main(){
    int t;
    cin>>t;
    while(t--){
        int i,j,n,m;
        cin>>n>>m;
        int boxes[n];
        rep(i,0,n) cin>>boxes[i];
        sort(boxes,boxes+m,greater<int>());
        for(int i=0;i<m;i++){
            int cuts = (int)log2(boxes[i]) - (int)log2(n);
            
        }

    }
}