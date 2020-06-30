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
#define INF 1000000
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
    
    int i, j, n, m, k, l, x;
    cin>>n>>m>>k;
    vector<pii> a, b, c, both;
    rep(i, 0, n){
      int t, c1, c2;
      cin>>t>>c1>>c2;
      if(c1 && c2){
        both.push_back({t,i});
      }
      else if(c1){
        a.push_back({t,i});
      }
      else if(c2){
        b.push_back({t,i});
      }
      else{
        c.push_back({t,i});
      }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(both.begin(), both.end());

    
    vector<int> ans;
    ll res = 0;

    int cnt = 0;
    i = 0, j = 0;
    bool bad = false;
    int sz1 = both.size(), sz2 = min((int)a.size(), (int)b.size());

    int must_both = max(0, 2*k - m);
    if(sz1 < must_both){
      cout<<"-1\n";
      return 0;
    }

    rep(i, 0, must_both){
      ans.push_back(both[i].second);
      res += both[i].first;
    }
    
    k -= must_both;

    while((j < sz2 || i < sz1) && cnt < k) {
      if((i < sz1 && j >= sz2) ||(i < sz1 && j < sz2 && both[i].first <= a[j].first + b[j].first)){
        ans.push_back(both[i].second);
        res += both[i].first;
        i++;
      }
      else if((j < sz2 && i >= sz1) || (j < sz2 && i < sz1 && both[i].first >= a[j].first + b[j].first)){
        ans.push_back(a[j].second);
        ans.push_back(b[j].second);
        res += (a[j].first + b[j].first);
        j++;
      }
      cnt++;
      // cerr<<i<<" "<<j<<" "<<res<<"\n";
    }

    if(cnt < k) {
      cout<<"-1\n";
      return 0;
    }

    int sz = ans.size();
    x = j, l = 0;
    sz1 = both.size(), sz2 = a.size();
    int sz3 = b.size(), sz4 = c.size();
    // cerr<<sz<<" ";
    while((i < sz1 || j < sz2 || x < sz3 || l < sz4) && sz < m) {
      vi mn = {INF, -1, -1};
      if(i < sz1) {
        mn = min(mn, {both[i].first, both[i].second,0});
      }
      if(j < sz2) {
        mn = min(mn, {a[j].first, a[j].second,1});
      }
      if(x < sz3) {
        mn = min(mn, {b[x].first, b[x].second,2});
      }
      if(l < sz4) {
        mn = min(mn, {c[l].first, c[l].second,3});
      }

      ans.push_back(mn[1]);
      res += mn[0];
      sz++;
      if(mn[2]==0) i++;
      else if(mn[2]==1) j++;
      else if(mn[2]==2) x++;
      else if(mn[2]==3) l++;
      // cerr<<i<<" "<<j<<" "<<res<<"\n";
    }
    // cerr<<sz<<" ";

    if(sz < m) {
      cout<<"-1\n";
    }
    else{
      assert((int)ans.size() == m);
      cout<<res<<"\n";
      for(int x: ans) cout<<x+1<<" ";
    }
    return 0;
}