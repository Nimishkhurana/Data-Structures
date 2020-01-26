#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];

        deque<int> dq;
        dq.push_back(0);
        int count=1;

        int i;
        for(i=1;i<5;i++){
            int front = arr[dq.front()];

            // cout<<front<<" ";

            if(arr[i]<front)
                count++;   
            
            while ((!dq.empty()) && arr[i] <= arr[dq.back()]) 
                dq.pop_back();
            
            dq.push_back(i);
        }

        for(;i<n;i++){
            int front = arr[dq.front()];
            // cout<<i<<" "<<front<<" ";

            if(arr[i]<front)
                count++;

            while ((!dq.empty()) && dq.front() <= i - 5) 
                dq.pop_front(); 

            while ((!dq.empty()) && arr[i] <= arr[dq.back()]) 
                dq.pop_back();
            
            dq.push_back(i);    
        }

        // cout<<arr[dq.front()];
        cout<<count<<endl;

    }
	return 0;
}

