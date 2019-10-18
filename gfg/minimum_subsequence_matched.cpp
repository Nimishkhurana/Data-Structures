#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void minimumSubSequenceMatching(string s, string t){
    unordered_map<char,int> freqRequired, freqMatched;
    int n1 = s.length();
    int n2 = t.length();

    if(n1<n2){
        cout<<-1<<endl;
        return;
    }
    int freqSatisfying = 0;

    for(int i=0;i<n2;i++)
        freqRequired[t[i]]++;
    
    // for(auto it = freqRequired.begin();it!=freqRequired.end();it++)
    //     cout<<it->first<<" "<<it->second<<"  ";
    // cout<<endl;
    
    int l=0,currLen=INT_MAX,minLen=INT_MAX,start=0;
    for(int r=0;r<n1;r++){
        // cout<<"l="<<l<<" r="<<r<<" freqSatisfying="<<freqSatisfying<<" freqsl="<<freqMatched[s[l]]<<endl;
        char ch = s[r];
        if(freqRequired.find(ch)!=freqRequired.end()){
            freqMatched[ch]++;
            if(freqMatched[ch] <= freqRequired[ch])
                freqSatisfying++;
        }
        if(freqSatisfying == n2){
            while(l<r){
                if(freqRequired.find(s[l]) != freqRequired.end()){
                    if(freqMatched[s[l]] > freqRequired[s[l]])
                        freqMatched[s[l]]--;
                     else 
                        break;
                }
                l++;
                // cout<<"l="<<l<<" r="<<r<<" freqSatisfying="<<freqSatisfying<<" freqsl="<<freqMatched[s[l]]<<endl;
            }
            currLen = r - l + 1;
            if(minLen > currLen){
                start = l;
                minLen = currLen;
            }
        }
            
            // cout<<ch<< " ";
            // cout<<"l="<<l<<" r="<<r<<" freqSatisfying="<<freqSatisfying<<" minLen="<<minLen<<" freqsl="<<freqMatched[s[l]]<<endl;     
    }

    if(minLen==INT_MAX)
        cout<<-1;
    else
        for(int i=start;i<minLen+start;i++)
            cout<<s[i];
    cout<<endl;
        
    
    // return minLen;
}


int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s,s2;
        getline(cin,s);
        getline(cin,s2);
        minimumSubSequenceMatching(s,s2);
    }  
}
