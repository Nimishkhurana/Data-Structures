#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll zeroes = n - m;
        ll groups = m + 1;
        ll k = floor(zeroes/groups);
        ll extraZeroGroups = zeroes%groups;
        ll totalSubarrays = n*(n+1)/2LL;
        ll zeroGroupSize = k*(k+1)/2LL;
        ll res;
        res = totalSubarrays - zeroGroupSize*groups - (k+1)*extraZeroGroups;

        cout<<res<<endl;
    }
    return 0;
}