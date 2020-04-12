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
        int n, i, x;
        cin>>n>>x;
        int s[n+1];
        int temp;
        rep(i,0,n){
            cin>>s[i];
        }

        s[n] = 0;

        sort(s, s+n+1);

        int res = -1;
        rep(i,0,n){
            int diff = max(0, s[i+1] - s[i] - 1);
            if(x > diff)
                x -= diff;
            
            else if(x==diff){
                res = s[i+1];
                break;
            }

            else if(x < diff){
                res = s[i] + x;
                break;
            }
        }

        if(i==n)
            res = s[n] + x;

        cout<<res<<"\n";
    }
    return 0;
}