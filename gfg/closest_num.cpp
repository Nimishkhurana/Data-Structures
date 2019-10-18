#include<iostream>
#include<cmath>
using namespace std;

int closestNumber(int n, int m){
    if(m==1)
        return n;
    int nabs = abs(n);
    int mabs = abs(m);
    
    int remabs = nabs%mabs;
    if(remabs>=float(mabs/2.0))
        nabs = nabs + (mabs-remabs);
    else
        nabs-=remabs;
    
    if(n<0)
        return -nabs;
    else
        return nabs;
    
}

int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<closestNumber(n,m)<<endl;  
    }
	return 0;
}