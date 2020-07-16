#include<bits/stdc++.h>
using namespace std;

// Hash: hash[l...l+m] = ((hash[l-1...l-1+m] - s[l]*(h))*d) + s[l+m]) % MOD
// h = d^(m-1)

const int MOD = 101, d = 256;
int pownk(int x, int e) {
  int res = 1;
  while(e) {
    if(e&1) 
      res = (res*x) % MOD;
    x = (x*x)%MOD;
    e >>= 1;
  }
  return res;
}

template< typename T>
vector<int> rabinKarpmp(T const &s, T const &p){
    int n = s.size(), m = p.size();
    int i = 0, j = 0;
    int h = pownk(d, m-1);
    int hashp = 0, hasht = 0;
    for(int i = 0; i < m; i++) {
      hashp = (hashp*d + p[i]) % MOD;
      hasht = (hasht*d + s[i]) % MOD;
    }

    vector<int> occurrences;
    for(int i = 0; i < n - m + 1; i++) {
      if(hashp == hasht) {
        bool bad = false;
        for(int j = 0; j < m; j++) {
          if(s[i+j] != p[j]) {
            bad = true;
            break;
          }
        }
        if(!bad) {
          occurrences.push_back(i);
        }
      }
      // update hash for next window
      if(i < n - m) {
        hasht = (((hasht - s[i]*h)*d + s[i+m]) % MOD + MOD) % MOD;
      }
    }
    
    return occurrences;
}
int main() {

}