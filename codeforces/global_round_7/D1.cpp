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

bool ispalindrome(string s, int l, int r){
    
    for(int i=l, j = r; i< l + (r-l+1)/2; i++, j--){
        if(s[i]!=s[j])
            return false;
    }

    return true;
}

int main(){
    
    fast 
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        string res1 = "";
        int i,j, l = 0;
        int n = (int)s.length();
        for(i=0, j = n-1; i<(n+1)/2 ; i++, j--){
            if(s[i]!=s[j])
                break;
            res1.pb(s[i]);
            l++;
        }

        if(i==(n+1)/2){
            cout<<s<<"\n";
            continue;
        }

        // cout<<res1<<" ";


        string res2 = "";
        int mxl = 0;
        int k;
        for(k = j;k >= i; k--){
            if(ispalindrome(s, i , k)){
                res2 = s.substr(i, k-i+1);
                mxl = k-i+1;
                break;
            }
        }

        string res3 = "";
        int mxr = 0;
        
        for(k = i;k<=j;k++){
            if(ispalindrome(s, k , j)){
                res3 = s.substr(k, j-k+1);
                mxr = j-k+1;
                break;
            }
        }

        // cout<<res2<<" "<<res3<<"\n";

        if(mxl >= mxr){
            res1 += res2;
        }
        else{
            res1 += res3;
        }

        res1 += s.substr(n-l, l);

        cout<<res1<<"\n";
            
    }
    return 0;
}