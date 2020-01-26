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

        // map of form (element->(index,freq))
        unordered_map<int,pair<int,int>> m;

        for(int i=0;i<n;i++){
            maxx = max(maxx,arr[i]);

            if(m.find(arr[i])==m.end())
                m[arr[i]] = {i,1};
            else
                m[arr[i]] = {i,m[arr[i]].second+1};        
        }

        // for(auto it=m.begin();it!=m.end();it++)
        //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;

        // cout<<maxx<<"\n\n";
        int currCount=0,maxCount=0;
        for(int i=1;i<n;i++){
            currCount=0;
            // cout<<arr[i]<<" ";
            for(int j=arr[i];j<=maxx;j+=arr[i]){
                if(m.find(j)!=m.end() && m[j].first<i)
                    currCount += m[j].second;
            }
            // cout<<currCount<<"  ";
            maxCount = max(maxCount,currCount);
        }

        cout<<max(maxCount,currCount)<<endl;

    }
}