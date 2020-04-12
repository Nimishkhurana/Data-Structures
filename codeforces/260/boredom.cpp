// similar to house robber
#include<bits/stdc++.h>
#include <iomanip>
#include<map>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>

vector<pair<ll,ll>> freq;
vector<ll> dp;

ll go(int n){
    for(int i=0;i<(int)freq.size();i++){
        int j = i-1;
        if(j>=0 && freq[j].first == freq[i].first - 1)
            j--;
        dp[i] = 1LL * freq[i].first * freq[i].second + ((j>=0)?dp[j]:0);
        if(i)
            dp[i] = max(dp[i], dp[i-1]);
    }
    int m = freq.size()-1;
    return dp[m];
}

int main(){
    ll i,n;
    cin>>n;
    ll num;
    dp.resize(n,0);
    map<ll,ll> um;
    rep(i,0,n){
        cin>>num;
        um[num]++;
    }

    for(auto x: um){
        // cout<<x.first<<" "<<x.second<<" ";
        freq.push_back(make_pair(x.first, x.second));
    }

    cout<<go(n)<<endl;

    return 0;
}