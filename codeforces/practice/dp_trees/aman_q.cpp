#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[100001];

int main(){
    int n,l;
    cin>>n>>l;

    if(n&1){
        cout<<0;
        return 0;
    }

    dp[0] = 1;
    dp[2] = 1;

    for(int i=4;i<=n;i+=2){
        for(int j=2;j<=l && j<=i;j+=2){
            dp[i]+=dp[i-j];
        }
    }

    cout<<dp[n];
}