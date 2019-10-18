#include<bits/stdc++.h>
using namespace std;

void swap (char* a, char* b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
}  


void allPermutation(string s){
    int n = s.length();

    bool isFinished = false;

    while(!isFinished){
        cout<<s<<endl;

        int firstIndex=-1;

        for(int i=n-2;i>=0;i--){
            if(s[i]<s[i+1]){
                firstIndex = i;
                break;
            }
        }
        // cout<<"First:"<<firstIndex<<endl;


        if(firstIndex == -1) isFinished = true;
        
        else{
            // cout<<"First:"<<firstIndex<<endl;
            int ceilIndex = firstIndex + 1;
        
            for(int i=firstIndex+2;i<n;i++){
                if(s[i]>s[firstIndex] && s[i]<=s[ceilIndex])
                    ceilIndex = i;
            }

            swap(&s[firstIndex],&s[ceilIndex]);

            sort(s.begin()+firstIndex+1,s.end());

        }

        
    }
    
}

int main(){
    string s = "ABCD";
    sort(s.begin(),s.end());
    // cout<<s<<endl;



    allPermutation(s);
}

