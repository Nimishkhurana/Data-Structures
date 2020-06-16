#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int maxx = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int currCount=0,maxCount=0;
        for(int i=1;i<n;i++){
            currCount=0;
            // cout<<arr[i]<<" ";
            for(int j=i-1;j>=0;j--){
                if(arr[j]%arr[i]==0)
                    currCount++;
            }
            // cout<<currCount<<"  ";
            maxCount = max(maxCount,currCount);
        }

        cout<<max(maxCount,currCount)<<endl;

    }
}