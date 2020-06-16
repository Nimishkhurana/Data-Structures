#include <iostream>
using namespace std;

int main() {
	long long int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        long long int arr[n];
        for(long long int i=0;i<n;i++) cin>>arr[i];

        if(k>=3*n && n&1)
            arr[n/2]=0;

        k = k%(3*n);

        for(long long int i=0;i<k;i++){
            arr[i%n] = arr[i%n]^arr[n-(i%n)-1];
        }

        for(long long int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
           
    }
	return 0;
}
