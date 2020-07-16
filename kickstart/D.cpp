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

struct Node {
  int room;
  Node* next;

  Node(int r) : room(r){}
};


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t, T;
    cin>>T;
    rep(t, 1, T+1) {
      int i, j, n, q;
      cin>>n>>q;
      int d[n];
      rep(i, 1, n) cin>>d[i];

      unordered_map<int, Node*> mp;
      Node dummy(0);
      Node *head = &dummy, *ptr = &dummy;
      rep(i, 1, n+1) {
        Node *temp = new Node(i);
        ptr->next = temp;
        ptr = ptr->next;
        mp[i] = temp;
      }

      vector<vector<int>> queries(q, vector<int>(3));
      rep(i, 0, q) {
        cin>>queries[i][0]>> queries[i][1];
        queries[i][2] = i;
      }

      sort(queries.begin(), queries.end());
      vector<int> ans(q);

      int q = 0;
      for(int room = 1; room <= n; room++) {
        while(queries[q][0] == room) {
          int ind = queries[q][2];
          ans[ind] = cur[queries[q][1]];
          q++;
        }

        if(d[door] < d[door+1]) {
          swap(cur[door], cur[door+1]);
        }
        else{

        }
      }
    }

      
    return 0;
}