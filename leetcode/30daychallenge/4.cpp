#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int> > strp;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            strp.push_back(make_pair(strs[i], i));
            sort(strp[i].first.begin(), strp[i].first.end());
        }
               
        
        sort(strp.begin(), strp.end());
        vector<vector<string>> res;
        
        int i = 0;
        while(i < n){
            // cout<<strp[i].first<<" ";
            vector<string> s;
            s.push_back(strs[strp[i].second]);
            while(i+1 < n && strp[i].first==strp[i+1].first){
                // cout<<strp[i].first<<" ";
                s.push_back(strs[strp[i+1].second]);
                i++;
            }
            i++;
            // cout<<"\n";
            res.push_back(s);
        }
        return res;
    }
};

int main(){
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    Solution S;
    vector<vector<string>> res = S.groupAnagrams(strs);
    cout<<"\n\n";
    for(vector<string>  vs: res){
        for(string s: vs) cout<<s<<" ";
        cout<<endl;
    }
        
}