#include<iostream>
using namespace std;

int longestPalindromicSubstring(string s){
    int n = s.length();
    bool dp[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                dp[i][j] = true;
        }
    }

    int start = 0;
    int len=1;
    bool flag;

    for(int gap=1;gap<n;gap++){
        flag=true;
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==1)
                dp[i][j] = s[i]==s[j] && dp[i][j-1];
            else    
                dp[i][j] = s[i]==s[j] && dp[i+1][j-1]; 
            
            if(flag && dp[i][j]){
                start = i;
                len = gap+1;
                flag = false;
            }
        }   
    }
    

    // cout<<"Longest Palindromic Substring: ";

    for(int i=start;i<start+len;i++)
        cout<<s[i];
    cout<<endl;

    return len;
}

int main(){
    string s;
    cin>>s;

    longestPalindromicSubstring(s);

}