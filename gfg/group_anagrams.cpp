#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> groupAnagrams(string str[], int n){

    for(int i=0;i<n;i++){
        sort(str[i].begin(),str[i].end());
    }

    unordered_map<string,int> m;

    for(int i=0;i<n;i++)
        m[str[i]]++;
    
    vector<int> freq;

    for(auto it=m.begin();it!=m.end();it++)
        freq.push_back(it->second);
    
    sort(freq.begin(),freq.end());

    return freq;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cin.ignore();
        string str[n];
        for(int i=0;i<n;i++) cin>>str[i];
        vector<int>ans = groupAnagrams(str,n);
        for(auto x:ans) cout<<x<<" ";
        cout<<endl;
    }
}
    
