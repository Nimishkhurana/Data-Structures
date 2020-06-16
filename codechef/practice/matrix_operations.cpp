#include <iostream>
using namespace std;

int main() {
	long int t;
    cin>>t;

    while(t--){
        long int n,m,q;
        cin>>n>>m>>q;

        long int row[n] = {0},col[m] = {0};

        long int temp;
        for(long int i=0;i<q;i++)
            for(long int j=0;j<2;j++){
                cin>>temp;
                if(j==0)
                    row[temp-1]++;
                else
                    col[temp-1]++;
            }
        
        long int count=0;
        for(long int i=0;i<n;i++){
            for(long int j=0;j<m;j++){
                temp = row[i] + col[j];
                if(temp&1)
                    count++;
            }
        }
        cout<<count<<endl;
    }
	return 0;
}
