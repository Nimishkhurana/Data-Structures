#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        string s1;
        cin>>s1;
        vector<string> v(k);
        for(int i = 0;i<k;i++) {
            cin>>v[i];
        }
        unordered_map<char,list<int>> m;
        for(int i=0;i<k;i++) {
            for(char j: v[i]) {
                m[j].push_back(i+1);
            }
        }
        unsigned int dp[k][n+1];
        for(int i = 0;i<k;i++) {
            for(int j=0;j<=n;j++) {
                if(j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = INT_MAX;
            }
        }
        for(int i = 1;i<=n;i++) {
            list<int> h = m[s1[i-1]];
            for(int j : h) {
                dp[j][i] = dp[j][i-1] + 1;
            }
        }
    }
}