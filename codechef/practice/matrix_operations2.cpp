#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
    cin>>t;

    while(t--){
        long long int n,m,q;
        cin>>n>>m>>q;

        long long int rowEven=0,colEven=0,rowOdd=0,colOdd=0;
        unordered_set<long long int> r,c;
        long long int temp;
        long long int row[n] = {0},col[m] = {0};
        for(long long int i=0;i<q;i++)
            for(long long int j=0;j<2;j++){
                cin>>temp;
                if(j==0){
                     row[temp-1]++;
                     r.insert(temp-1);
                }
                   
                else{
                    col[temp-1]++;
                    c.insert(temp-1);
                }     
            }
        
        long long int rowQCount = r.size();
        long long int colQCount = c.size();
        
        // cout<<rowQCount<<" "<<colQCount<<endl;
        
        for(long long int i=0;i<n;i++){
            temp = row[i];
            
            if(temp>0){
                temp&1?rowOdd++:rowEven++;
            }        
        } 

        for(long long int i=0;i<m;i++){
            temp = col[i];
            if(temp>0){
                temp&1?colOdd++:colEven++;
            }      
        }

        long long int count=0;
       
        count += rowOdd*colEven + rowEven*colOdd;
        // cout<<"rowOdd="<<rowOdd<<" rowEven="<<rowEven<<" colOdd="<<colOdd<<" colEven="<<colEven<<endl;
        // cout<<count<<" ";

        count+= colOdd*(n-rowQCount) + rowOdd*(m-colQCount);
       
        cout<<count<<endl;
    }
	return 0;
}
