//Author: nimishkhurana
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
    
    int i, j, n, k;
    cin>>n>>k;
    vector<int> a, b, both;
    rep(i, 0, n){
      int t, c1, c2;
      cin>>t>>c1>>c2;
      if(c1 && c2){
        both.push_back(t);
      }
      else if(c1){
        a.push_back(t);
      }
      else if(c2){
        b.push_back(t);
      }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end());


    vector<int> ans;
    int res = 0;

    int cnt = 0;
    i = 0, j = 0;
    bool bad = false;
    int sz1 = both.size(), sz2 = min((int)a.size(), (int)b.size());
    while((j < sz2 || i < sz1) && cnt < k) {
      if((i < sz1 && j >= sz2) ||(i < sz1 && j < sz2 && both[i] <= a[j] + b[j])){
        ans.push_back(both[i]);
        res += both[i];
        i++;
      }
      else if((j < sz2 && i >= sz1) || (j < sz2 && i < sz1 && both[i] >= a[j] + b[j])){
        ans.push_back(a[j]);
        ans.push_back(b[j]);
        res += (a[j] + b[j]);
        j++;
      }
      cnt++;
      // cerr<<i<<" "<<j<<" "<<res<<"\n";
    }

    if(cnt < k) {
      cout<<"-1\n";
    }
    else{
      cout<<res<<"\n";
    }
   
    return 0;
}