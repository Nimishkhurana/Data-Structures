#include<iostream>
using namespace std;

bool stringValue(string s){
    int n = s.length();
    for(int i=0;i<n-2;i+=2){
        int d1 = s[i]-'0', d2 = s[i+2]-'0';
        switch (s[i+1])
        {
        case 'A':
            // cout<<d1 & d2;
            s[i+2] = (char)((d1 & d2)+'0');
            break;
        case 'B':
            s[i+2] = (char)((d1 | d2)+'0');
            break;
        case 'C':
            s[i+2] = (char)((d1 ^ d2)+'0');
            break;
        default:
            break;
        }
    }

    return s[n-1]-'0';
}


int main()
 {
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        
        getline(cin,s);

        cout<<stringValue(s)<<endl;   
    }
	
	return 0;
}