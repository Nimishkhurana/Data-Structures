#include<iostream>
using namespace std;


void printUncommonChars(string s1, string s2, int n1, int n2){
    int freq[26]={0};
    string res;

    for(int i=0;i<n2;i++)
        freq[s2[i]-'a']=1;
    
    for(int i=0;i<n1;i++){
        char ch = s1[i];
        if(freq[ch-'a']==0)
            res.push_back(s1[i]);
        else
            freq[ch-'a']=2;
    }

    for(int i=0;i<n2;i++)
        if(freq[s2[i]-'a']==1){
            // cout<<s2[i]<<" ";
            res.push_back(s2[i]);
        }

    if(res.empty())
        cout<<-1<<endl;       
    else
        cout<<res<<endl;


}
int main()
 {
	int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s1,s2;
        
        getline(cin,s1);
        getline(cin,s2);

        int n1 = s1.length();
        int n2 = s2.length();

        printUncommonChars(s1,s2,n1,n2);   
    }
	return 0;
}