#include<iostream>
using namespace std;

string sumLargeNums(string num1, string num2){
    int n1 = num1.length();
    int n2 = num2.length();

    if(n2>n1){
        return num1;
    }
       
    
    string res(n1,' ');
    int carry=0;

    for(int i=n1-1,j=n2-1;i>=0;i--,j--){
        int d1 = num1[i]-'0', d2 = j>=0?num2[j]-'0':0;
        int d3 = d1+d2+carry;
        carry = d3/10;
        d3 %= 10;
        res[i]=(char)(d3+'0');
    }
    if(carry)
        res.insert(0,"1");

    if(res.length()>n1)
        return num1;
    else 
        return res;


}
int main()
 {
	int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string num1,num2;
        cin>>num1>>num2;


        cout<<sumLargeNums(num1,num2)<<endl;   
    }
	return 0;
}