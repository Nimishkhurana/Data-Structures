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
#define INF 1000000000

// template <typename T>
// ostream& operator << (ostream& stream, const pair<T,T> &p) {
//     return stream<<"("<<p.first<<","<<p.second<<") ";
// }

// ostream& operator << (ostream& stream, const Node &n) {
//     return stream<<"("<<n.total<<","<<n.prefix<<","<<n.suffix<<","<<n.subsum<<")\n";
// } 

const int mxN = 1e5+1;
int n, a[mxN];

struct Node{
    int total, prefix, suffix, subsum; 
};
Node tree[4*mxN];
class SegmentTree{
    int left(int node){return node*2;}
    int right(int node){ return node*2+1;}
    
    void merge(Node &res, Node &leftChild, Node &rightChild){
        res.total = leftChild.total + rightChild.total;
        res.prefix = max(leftChild.prefix, leftChild.total + rightChild.prefix);
        res.suffix = max(rightChild.suffix, leftChild.suffix + rightChild.total);
        res.subsum = max(leftChild.subsum, max(rightChild.subsum, leftChild.suffix + rightChild.prefix));
    }
public:
    SegmentTree(){
        memset(tree, 0, sizeof(tree));
    }
    // void printTree(){
    //     int i;
    //     rep(i,0,4*n)
    //         cout<<tree[i];
    // }

    void build(int node=1, int tl=0, int tr=n-1){
        if(tr < tl) return;
        if(tl==tr){
            tree[node].total = a[tl];
            tree[node].prefix = a[tl];
            tree[node].suffix = a[tl];
            tree[node].subsum = a[tl];
            return;
        }

        int tm = (tl+tr)/2; 
        build(left(node), tl, tm);
        build(right(node), tm+1, tr);
        merge(tree[node], tree[left(node)], tree[right(node)]);
    }

    Node query(int ql, int qr, int node=1, int tl=0, int tr=n-1){
        if(ql<=tl && tr<=qr)
            return tree[node];
        
        int tm = (tl+tr)/2;
        Node res;

        if(qr < tm+1)
            res = query(ql, qr, left(node), tl, tm);
        else if(ql > tm)
            res = query(ql, qr, right(node), tm+1, tr);
        
        else{
            Node lnode = query(ql, qr, left(node), tl, tm);
            Node rnode = query(ql, qr, right(node), tm+1, tr);
            merge(res, lnode, rnode);
        }
        return res;
    }
};

int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int i, j;
    cin>>n;
    rep(i, 0, n) cin>>a[i];
    stack<int> s;

    vector<int> nextGreater(n, n), prevGreater(n, -1);
    rep(i, 0, n){
        while(!s.empty() && a[s.top()] <= a[i]){
            s.pop();
        } 

        if(!s.empty()) prevGreater[i] = s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();

    rrep(i,n-1, 0){
        while(!s.empty() && a[s.top()] <= a[i]){
            s.pop();
        } 

        if(!s.empty()) nextGreater[i] = s.top();
        s.push(i);
    }

    rep(i, 0, n) cerr<<nextGreater[i]<<" \n"[i==n-1];
    rep(i, 0, n) cerr<<prevGreater[i]<<" \n"[i==n-1];

    SegmentTree sg;
    sg.build();

    int ans = 0;
    rep(i, 0, n){
        int rsum = 0, lsum = 0;
        if(i < n && i+1 <= nextGreater[i]-1)
            rsum = sg.query(i+1, nextGreater[i]-1).prefix;
        if(i && prevGreater[i]+1 <= i-1)
            lsum = sg.query(prevGreater[i]+1, i-1).suffix;
        ans = max(ans, max(0, lsum) + max(0, rsum));
    }

    cout<<ans<<"\n";
   
    return 0;
}