#include<iostream>
using namespace std;

// .....'m','n','ng','o'.....
int stringComparision(string s1, string s2){
    int n1 = s1.length(), n2 = s2.length();

    if(n1 <= n2){
        for(int i=0;i<n1;i++){
            if(i!=n1-1 && s1[i]=='n' && s2[i]=='n'){
                if(s1[i+1]=='g' && s2[i+1]!='g')
                    return 1;
                else if(s2[i+1]=='g' && s1[i+1]!='g')
                    return -1;
            }
            if(s1[i]>s2[i])
                return 1;
            else if(s1[i] < s2[i])
                return -1;
        }
        if(n1==n2)
            return 0;
        return -1;
    }
    else{
        for(int i=0;i<n2;i++){
            if(i!=n2-1 && s1[i]=='n' && s2[i]=='n'){
                if(s1[i+1]=='g' && s2[i+1]!='g')
                    return 1;
                else if(s2[i+1]=='g' && s1[i+1]!='g')
                    return -1;
            }
            if(s1[i]>s2[i])
                return 1;
            else if(s1[i] < s2[i])
                return -1;
        }
        return 1;

    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<stringComparision(s1,s2)<<endl;
    }
}