#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.length();
        int ind[256];
        memset(ind,-1,sizeof(ind));

        int j=0,max_len=0;

        for(int i=0;i<n;i++){
            int last_ind = ind[int(s[i])];
            if(last_ind != -1){
                j = max(j,last_ind+1);
                
            }
            // else j++;
            ind[int(s[i])] = i;
            max_len = max(max_len,i-j+1);
        }

        cout<<max_len<<endl;

    }
}