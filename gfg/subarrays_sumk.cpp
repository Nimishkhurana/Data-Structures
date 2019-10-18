#include<bits/stdc++.h>
using namespace std;

int subarraysSumK(int arr[],int n,int k){
    int curr_sum = 0,count=0;
    unordered_map<int,int> m;

    for(int i=0;i<n;i++){   
        curr_sum+=arr[i];

        if(curr_sum==k)
            count++;
        
        int exceeded = curr_sum - k;

        if(m.find(exceeded)!=m.end())
            count+=m[exceeded];
        
        m[curr_sum]+=1;
    }
    return count;
}

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        cin.ignore();
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cin>>k;
        cout<<subarraysSumK(arr,n,k)<<endl;
    }
}