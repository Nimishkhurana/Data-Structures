#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umapi unordered_map<int,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int> 
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   
    int i, j;
    int n;
    cin>>n;
    int a[n], b[n], place[n+1];
    rep(i, 0, n) {
        cin>>a[i];
        place[a[i]] = i+1;
    }
    rep(i, 0, n) cin>>b[i];

    int diff[n];
    vector<int>freq(n, 0);
    rep(i, 0, n){
        diff[i] = (i+1 - place[b[i]] + n)%n;
        freq[diff[i]]++;
    }

    sort(freq.begin(), freq.end(), greater<int>());
    int mx = freq[0];
    cout<<mx;

   
    return 0;
}