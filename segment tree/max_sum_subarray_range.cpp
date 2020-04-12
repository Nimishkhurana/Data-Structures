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

struct Node{
    ll total, prefix, suffix, subsum; 
};

ostream& operator << (ostream& stream, const Node &n) {
    return stream<<"("<<n.total<<","<<n.prefix<<","<<n.suffix<<","<<n.subsum<<")\n";
} 

const ll mxN = 1e5+1;
ll n,q, a[mxN];



class SegmentTree{
    Node tree[4*mxN];
    ll left(ll node){return node*2;}
    ll right(ll node){ return node*2+1;}
    
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
    void printTree(){
        ll i;
        rep(i,0,4*n)
            cout<<tree[i];
    }

    void build(ll node=1, ll tl=0, ll tr=n-1){
        if(tr < tl) return;
        if(tl==tr){
            tree[node].total = a[tl];
            tree[node].prefix = a[tl];
            tree[node].suffix = a[tl];
            tree[node].subsum = a[tl];
            return;
        }

        ll tm = (tl+tr)/2; 
        build(left(node), tl, tm);
        build(right(node), tm+1, tr);
        merge(tree[node], tree[left(node)], tree[right(node)]);
    }

    void update(ll ind, ll val, ll node=1, ll tl=0, ll tr=n-1){
        if(tr<tl || ind<tl || tr<ind) return;
        if(tl==tr){
            tree[node].total = val;
            tree[node].prefix = val;
            tree[node].suffix = val;
            tree[node].subsum = val;
            return;
        }

        ll tm = (tl+tr)/2; 
        update(ind, val, left(node), tl, tm);
        update(ind, val, right(node), tm+1, tr);
        merge(tree[node], tree[left(node)], tree[right(node)]);
    }

    Node query(ll ql, ll qr, ll node=1, ll tl=0, ll tr=n-1){
        if(ql<=tl && tr<=qr)
            return tree[node];
        
        ll tm = (tl+tr)/2;
        Node res;

        if(qr < tm+1 )
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
    ll T;
    cin>>T;
    while(T--){
        SegmentTree sg;
        cin>>n>>q;
        ll i;
        rep(i,0,n){
            cin>>a[i];
        }
        sg.build();

        rep(i,0,q){
            char type;
            cin>>type;
            if(type=='U'){
                ll ind, val;
                cin>>ind>>val;
                sg.update(--ind, val);
            }
            else if(type=='Q'){
                ll l, r;
                cin>>l>>r;
                l--, r--;
                Node lnode, mnode, rnode;
                ll res = 0;
                if(l){
                    lnode = sg.query(0, l-1);
                    res += max(0LL, lnode.suffix);
                }
                    
                mnode = sg.query(l, r);
                res += mnode.total;

                if(r<n-1){
                    rnode = sg.query(r+1, n-1);
                    res += max(0LL, rnode.prefix);
                }
                    
                cout<<res<<"\n";
            } 
            else if(type=='P')
                sg.printTree(), cout<<"\n";
        }
    }
    return 0;
}