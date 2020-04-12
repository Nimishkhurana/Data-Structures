#include<bits/stdc++.h>
using namespace std;

int findUpper(vector<int> arr, int size, int x){
    int l = 0,r = size-1;

    while(l<r){
        int mid = l + (r - l)/2;

        if(arr[mid]<=x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}

vector<int> getNearestStores(vector<int> houses, vector<int> stores){
    sort(stores.begin(),stores.end());

    vector<int> res;

    for(int i=0;i<houses.size();i++){
        // cout<<houses[i]<<" ";
        int gr  = lower_bound(stores.begin(),stores.end(),houses[i]) - stores.begin();
        if(gr == stores.size() || (gr>0 && houses[i] - stores[gr-1] <= stores[gr] - houses[i]))
            res.push_back(stores[gr-1]);
        else 
            res.push_back(stores[gr]);
    }
    return res;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<int> houses(m), stores(n);
    for(int i=0;i<m;i++){
        cin>>houses[i];
    }
    for(int i=0;i<n;i++){
        cin>>stores[i];
    }

    vector<int> nearest = getNearestStores(houses,stores);

    for(int i=0;i<nearest.size();i++)
        cout<<nearest[i]<<" ";

}
// 3 5
// 5 10 17
// 1 5 20 11 16