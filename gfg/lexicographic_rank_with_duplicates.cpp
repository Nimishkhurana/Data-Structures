#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int fac(int n){
    if(n==0 || n==1)
        return 1;
    return n*fac(n-1);
}

int lexRank(string s){
    int n = s.size();

    int rank=1;
    
    for(int i=0;i<n;i++){
        char ch = s[i];
        int less_than = 0;
        int freq[52] = {0};
        int d_count=1;

        for(int j = 0;j<52;j++){
            freq[j] = 0;
        }

        for(int j=i+1;j<n;j++){
            if(s[j]<ch)
                less_than+=1;  
        }
        for(int j=i;j<n;j++){
            if(int(s[j])>='A' && int(s[j])<='Z')
                freq[int(s[i])-'A'+26]+=1;
            else
                freq[int(s[i])-'a']+=1;
        }

        for(int j = 0;j<52;j++){
            cout<<freq[j]<<" ";
            d_count*=fac(freq[j]);
        }
            

        
        rank += (less_than*fac(n-i-1)) / d_count;

        // cout<<rank<<" "<<d_count<<"  ";
    }

    return rank;
}

// Driver Program 
int main() 
{ 
    // cout<<fac(2)<<endl;
    // Test case 1 
    string s1 = "abab"; 
    cout << "Rank of " << s1 << " is: "
         << lexRank(s1) << endl; 
  
    // Test case 2 
    string s2 = "settLe"; 
    cout << "Rank of " << s2 << " is: "
         << lexRank(s2) << endl; 
  
    return 0; 
} 