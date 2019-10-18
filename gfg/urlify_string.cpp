#include<iostream>
#include<string.h>
using namespace std;

void urlify(char* s){
    int n = strlen(s);
    cout<<n<<endl<<s<<endl;
    int spaces=0;

    for(int i=0;i<n;i++){
        if(s[i]==' '){
            spaces++;
        }
    }
    int ind=n+2*spaces-1;
    s[ind+1]='\0';
    for(int i=n-1;i>=0;i--){
        
        if(s[i]!=' '){
            s[ind--]=s[i];
        }
        else{
            s[ind--]='0';
            s[ind--]='2';
            s[ind--]='%';
        }
    }
    cout<<s;
}

int main()
 {
	char *s = new char[1001];
    cin.getline(s,1000);
    urlify(s);
	return 0;
}