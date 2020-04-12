#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;i++)
#define rrep(i,b,a) for(i=b;i>=a;i--)
#define ld long double
#define ll long long
#define umap unordered_map<int,int>
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const int mxN = 1e3;
int a[mxN], n, q;

class SegmentTree{
    int tree[4*mxN] = {0};
    int lazy[4*mxN] = {0};
    int left(int node){ return 2*node;}
    int right(int node){return 2*node+1;}
    void push(int node, int lt, int rt){
        tree[node] += (rt - lt + 1)*lazy[node];
        if(lt!=rt){
            lazy[left(node)] += lazy[node];
            lazy[right(node)] += lazy[node];
        }
        lazy[node] = 0;
    }
public:

    void update(int diff, int lq, int rq, int node = 1, int lt = 0, int rt = n-1){
        if(lq<=lt && rt<=rq){
            lazy[node] += diff;
            push(node, lt, rt);
            return;
        }

        push(node, lt, rt);
        int mid = (lt+rt)/2;
        if(lq <= mid)
            update(diff, lq, rq, left(node), lt, mid);
        if(mid+1 <= rq)
            update(diff, lq, rq, right(node), mid+1, rt);

        tree[node] = tree[left(node)] + tree[right(node)];
    }

    int query(int lq, int rq, int node = 1, int lt = 0, int rt = n-1){
        
        push(node, lt, rt);

        if(lq<=lt && rt<=rq) return tree[node];

        int mid = (lt+rt)/2;
        int lsum = 0, rsum = 0;

        if(lq <= mid)
            lsum = query(lq, rq, left(node), lt, mid);
        if(mid+1 <= rq)
            rsum = query(lq, rq, right(node), mid+1, rt);
        return lsum + rsum;
    }

    void printTree(){
        int i;
        rep(i,0,4*n)
            cout<<tree[i]<<" \n"[i==4*n-1];
        rep(i,0,4*n)
            cout<<lazy[i]<<" \n"[i==4*n-1];
    }
    
};

int main(){

    cin>>n;
    SegmentTree sg;
    int i;
    rep(i,0,n){
        cin>>a[i];
        sg.update(a[i], i, i);
    }

    cin>>q;
    rep(i,0,q){
        char type;
        cin>>type;
        if(type=='u'){
            int l,r,diff;
            cin>>l>>r>>diff;
            sg.update(diff, l, r);
        }
        else if(type=='q'){
            int l,r;
            cin>>l>>r;
            cout<<sg.query(l,r)<<"\n";
        }
        else if(type=='p')
            sg.printTree();
    }


}