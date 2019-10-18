#include<bits/stdc++.h>
using namespace std;

string removeAlternateChars(string s){
    string res;
    unordered_map<char,bool> st;

    for(char ch:s){
        char chl = tolower(chl);
        if(st.find(chl)==st.end() || st[chl]==false){
            res.push_back(ch);
            st[chl]=true;
        }
        else st[chl]=false;
    }
    return res;
}

int main(){
    int t;
    
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        
        cout<< removeAlternateChars(s)<<endl;
    }
    
}
