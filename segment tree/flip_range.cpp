#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<ll,ll>
#define pb push_back
#define mk make_pair
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mxN = 1e5+1;
int n,q;
int a[mxN];
int tree[4*mxN];
bool lazy[4*mxN];

int left(int node){ return node*2;}
int right(int node){ return node*2+1;}

void build(int node = 1, int tl = 0, int tr = n-1){
    if(tl>tr) return;

    if(tl==tr){
        tree[node] = a[tl];
        return;
    }

    int tm = (tl+tr)/2;
    build(left(node), tl, tm);
    build(right(node), tm+1, tr);

    tree[node] = tree[left(node)] + tree[right(node)];
}

void push(int node, int tl, int tr){
    if(lazy[node]==false) return;
    tree[node] = -tree[node];
    if(tl != tr){
        lazy[left(node)] = !lazy[left(node)];
        lazy[right(node)] = !lazy[right(node)]; 
    }
    lazy[node] = false;
}

void update(int ql, int qr, int node = 1, int tl = 0, int tr = n-1){

    if(ql <= tl && tr <= qr){
        tree[node] = -1 * tree[node];
        if(tl != tr){
            lazy[left(node)] = !lazy[left(node)];
            lazy[right(node)] = !lazy[right(node)]; 
        }
        return;
    }

    push(node, tl, tr);

    int tm = (tl+tr)/2;
    if(ql <= tm)
        update(ql, qr, left(node), tl, tm);
    if(tm+1 <= qr)
        update(ql , qr, right(node), tm+1, tr);
    
    tree[node] = tree[left(node)] + tree[right(node)];
}

int query(int ql, int qr, int node = 1, int tl = 0, int tr = n-1){

    push(node, tl, tr);

    if(ql <= tl && tr <= qr){
        return tree[node];
    }

    int lsum = 0, rsum = 0;
    int mid = (tl + tr)/2;
    if(ql <= mid)
        lsum = query(ql, qr, left(node), tl, mid);
    if(qr >= mid+1)
       rsum = query(ql, qr, right(node), mid+1, tr);

    return lsum + rsum;
}

void printTree(){
        int i;
        rep(i,1,2*n)
            cout<<tree[i]<<" \n"[i==2*n-1];
        rep(i,1,2*n)
            cout<<lazy[i]<<" \n"[i==2*n-1];
}

int main(){
    cin>>n;
    int i;
    rep(i,0,n) cin>>a[i];

    build();
    cin>>q;
    rep(i,0,q){
        char type;
        cin>>type;
        if(type == 'u'){
            int l, r;
            cin>>l>>r;
            update(l , r);
        }
        else if(type == 'q'){
            int l, r;
            cin>>l>>r;
            cout<<query(l ,r)<<"\n";
        }
        else if(type == 'p')
            printTree();
    }
    return 0;
}
