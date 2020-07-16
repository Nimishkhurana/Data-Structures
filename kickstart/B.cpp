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
#define MOD 1000000007
#define INF 1000000000
template <typename T>
ostream& operator << (ostream& stream, const pair<T,T> &p) {
    return stream<<"("<<p.first<<","<<p.second<<") ";
}


int main(){
    fastIO
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    int t, T;
    cin>>T;
    rep(t, 1, T+1) {
      cout<<"Case #"<<t<<": ";
      int i, j, k;
      cin>>k;
      vector<int> a(k);
      rep(i, 0, k) {
        cin>>a[i];
      }

      i = 0;
      int cnt = 0, rem = 0, len, prev;
      while(i+1 < k && a[i]==a[i+1]) i++;
      if(i >= k-2) {
        cout<<cnt<<"\n";
        continue;
      }
      if(a[i] < a[i+1]) {
        prev = 1;
        while(i+1 < k && a[i] < a[i+1] || a[i] == a[i+1]) {
          if(a[i] < a[i+1]) prev++;
          if(prev == 5) {
            prev = 1;
            cnt++;
          }
          i++;
        } 
  
        if(!cnt) {
          prev = 4;
        }
        
      }
      else {
        prev = 4;
        while(i+1 < k && a[i] > a[i+1] || a[i] == a[i+1]) {
          if(a[i] > a[i+1]) prev--;
          if(prev == 0) {
            prev = 4;
            cnt++;
          }
          i++;
        } 
  
        if(!cnt) {
          prev = 1;
        }
        
      }
      // cerr<<cnt<<" "<<prev<<"\n";
      i++;
      while(i < k) {
        if(a[i] > a[i-1]) {
          prev++;
          if(prev == 5) {
            prev = 1;
            cnt++;
          }
        }
        else if(a[i] < a[i-1]) {
          prev--;
          if(prev == 0) {
            prev = 4;
            cnt++;
          }
        }
        // cerr<<i<<" "<<prev<<" "<<cnt<<"\n";
        i++;
      }

      cout<<cnt<<"\n";
    }

      
    return 0;
}