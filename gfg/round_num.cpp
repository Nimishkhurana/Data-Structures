#include <iostream>
using namespace std;

int main() {
	int t;
	int carry;
	string num;
	cin>>t;
	cin.ignore();
	while(t--){
	    carry=0;
	    getline(cin,num);
	    int n = num.length();
	    if(num[n-1]-'0' > 5){
	        carry=1;
	        for(int i=n-2;i>=0 && carry==1;i--){
	            // cout<<num[i];
	            int t = num[i]-'0'+carry;
                // cout<<t;
	            carry = t/10;
	            num[i] = (char)(t%10+'0');
	            // cout<<num[i];
	        }
	    }
	    num[n-1]='0';
	    
	    if(carry)
	        num.insert(0,"1");
	 
	    cout<<num<<endl;
	}
	return 0;
}