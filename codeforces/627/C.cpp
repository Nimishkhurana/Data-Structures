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
        string s;
        cin>>s;
        int i, n = (int)s.length();
        int curr = 0, mx = 0;
        rep(i,0,n){
            char ch = s[i];
            if(ch == 'L'){
                curr++;
            }
            else{
                mx = max(curr, mx);
                curr = 0;
            }
        }

        mx = max(curr, mx);
        cout<<mx + 1<<endl;
    }
    return 0;
}