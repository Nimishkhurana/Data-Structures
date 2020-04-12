#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MOD = 1000000007;
int dp[102][2];

void modAdd(int &a, int b){
    a = (a + b)%MOD;
}

int main(){
    int i,j,n,k,d;
    cin>>n>>k>>d;

    if(n<d){
        cout<<0;
        return 0;
    }
    if(n==d){
        cout<<1;
        return 0;
    }

    dp[0][0] = 1, dp[0][1] = 0;

    rep(i,1,n+1){
        rep(j,1,k+1){
            if(i-j < 0) break;

            if(j<d){
                modAdd(dp[i][0], dp[i-j][0]);
                modAdd(dp[i][1], dp[i-j][1]);
            }
            else{
                modAdd(dp[i][1], dp[i-j][0]);
                modAdd(dp[i][1], dp[i-j][1]);
            }
        }
    }

    cout<<dp[n][1];   
}