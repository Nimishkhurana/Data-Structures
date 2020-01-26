#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<pair<string,int>> p;
        unordered_map<string,pair<int,int>> m;
        pair<string,int> temp;
        for(int i=0;i<n;i++){
            cin>>temp.first>>temp.second;
            p.push_back(temp);
            if(temp.second==0){
                m[temp.first].first++;
            }
            else if(temp.second==1){
                m[temp.first].second++;
            }
        }
        unordered_map<string,pair<int, int>>::iterator itr; 
        int count=0;
        for(itr = m.begin();itr!=m.end();itr++){
            count+=max(itr->second.first,itr->second.second);
        }

        cout<<count<<endl;
    }
}