//Author: nimishkhurana
// Source: https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915
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
const int mxn = 2e5;
const int mxlgn = 20;
const int SIZE = 8*mxn*mxlgn;
int n, q;
#define M ((L+R)/2)

int l[SIZE], r[SIZE], st[SIZE], NODES = 0;
int newleaf(int value) {
    int p = ++NODES;
    l[p] = r[p] = 0; // null
    st[p] = value;
    return p;
}
int newparent(int lef, int rig) {
    int p = ++NODES;
    l[p] = lef;
    r[p] = rig;
    st[p] = st[lef] + st[rig]; // immediately update value from children
    return p;
}

int build(int arr[], int L=0, int R=n-1) {
    if (L == R) return newleaf(arr[L]); // construct as leaf
    else return newparent(build(arr, L, M), build(arr, M+1, R)); // construct as parent
}

// return an int, a pointer to the new root of the tree
int update(int i, int x, int p, int L=0, int R=n-1) {
    if (L == R) return newleaf(st[p] + x);
    if (i <= M) return newparent(update(i, x, l[p], L, M), r[p]);
    else        return newparent(l[p], update(i, x, r[p], M + 1, R));
}

int query(int node, int ql, int qr, int L=0, int R=n-1){
    if(L > R || ql > qr || qr < L || ql > R) return 0;
    if(L == R) return st[node];
    else return query(l[node], ql, qr, L, M) + query(r[node], ql, qr, M+1, R);
}


int main(){
    fastIO
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    
   
    return 0;
}