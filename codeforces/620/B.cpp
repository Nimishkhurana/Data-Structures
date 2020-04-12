#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
// #define umap unordered_map<ll,ll>
#define pb push_back

bool isPalindrome(string s) { 
    int l = 0; 
    int h = s.length() - 1; 
   
    while (h > l) { 
        if (s[l++] != s[h--]) { 
            return false;
        } 
    } 
    return true;
} 

int main(){
    int n,len;
    cin>>n>>len;
    unordered_map<string,int> umap;
    int i;
    string a[n];
    rep(i,0,n){
        string s;
        cin>>s;
        a[i] = s;
        umap[s] = i;
    }

    bool vis[n] = {0};
    string res;
    rep(i,0,n){
        string s = a[i];
        if(isPalindrome(s))
                continue;
        if(!vis[i]){
            vis[i] = true;
            reverse(s.begin(), s.end());
            if(umap.find(s) != umap.end()){
                res += s;
                vis[umap[s]] = true;    
            }
        }
    }
    // rep(i,0,n)
    //     cout<<vis[i]<<" ";

    // cout<<endl;
    // cout<<res<<endl;
    string rev(res.begin(), res.end());
    reverse(rev.begin(), rev.end());

    int maxLen = -1, ind  = -1;
    rep(i,0,n){
        if(!vis[i] && isPalindrome(a[i])){
            // cout<<i<<endl;
            if(maxLen < (int)a[i].length()){
                maxLen = (int)a[i].length();
                ind  = i;
            }
        }
    }
    if(ind != -1)
        res += a[ind];

    res += rev;
    cout<<res.length()<<endl;
    cout<<res<<endl;

    return 0;
}
