#include<iostream>
#include<cstring>
using namespace std;

char* countSort(char arr[])
{
    int n = strlen(arr);
    // cout<<n;
    int freq[26];
    char* ans = new char[n];

    for(int i=0;i<26;i++) freq[i]=0;
    

    for(int i=0;i<n;i++)
        freq[arr[i]-'a']++;
    
    for(int i=1;i<26;i++){
        // cout<<freq[i]<<" ";
        freq[i] += freq[i-1];

    }
        
    
    for(int i=0;i<n;i++){
        char ch = arr[i];
        ans[freq[ch-'a']-1] = ch;
        freq[ch-'a']--;
    }

    return ans;    
}

int main(){
    int n;
    cin>>n;
    char arr[n];
    cin>>arr;
    cout<<countSort(arr);
}