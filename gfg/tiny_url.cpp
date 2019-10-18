#include<iostream>
#include<algorithm>
using namespace std;


string map = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//len = 62
string idTotinyURL(int id){
    string tinyURL;
    while(id){
        tinyURL.push_back(map[id%62]);
        id/=62;
    }
    reverse(tinyURL.begin(),tinyURL.end());
    return tinyURL;
}

int tinyURLToId(string tinyURL){
    int id=0;
    for(int i=0;i<tinyURL.length();i++){
        char ch = tinyURL[i];
        if(ch>='a' && ch<='z')
            id = id*62 + ch-'a';
        if(ch>='A' && ch<='Z')
            id = id*62 + ch-'a'+26;
        if(ch>='0' && ch<='9')
            id = id*62 + ch-'a'+52;
    }
    return id;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int id;
        cin>>id;
        string tinyURL;
        tinyURL = idTotinyURL(id);
        int id_ = tinyURLToId(tinyURL);
        cout<<tinyURL<<endl;
        cout<<id_<<endl;
    }
}

