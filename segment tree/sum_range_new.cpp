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

const int mxN = 1e5;
int a[mxN], n, q;

class SegmentTree{
    int tree[4*mxN] = {0};
    int left(int node){ return 2*node;}
    int right(int node){return 2*node+1;}
public:

    void build(int a[], int node=1, int l=0, int r=n-1){
        if(r<l) return;
        if(l==r){
            tree[node] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a, left(node), l, mid);
        build(a, right(node), mid+1, r);

        tree[node] = tree[left(node)] + tree[right(node)];
    }

    void update(int ind, int diff, int node=1, int l=0, int r=n-1){
        if(r < l || r < ind || ind < l) return;
        
        if(l==r){
            tree[node] += diff;
            return;
        }

        int mid = (l+r)/2;
        update(ind, diff, left(node), l, mid);
        update(ind, diff, right(node), mid+1, r);
        tree[node] = tree[left(node)] + tree[right(node)];
    }

    int query(int lq, int rq, int node=1, int lt=0, int rt=n-1){
        if(lt>rt || rt<lq || rq<lt) return 0;

        if(lq<=lt && rt<=rq) return tree[node];

        int mid = (lt+rt)/2;
        int lsum = query(lq, rq, left(node), lt, mid );
        int rsum = query(lq, rq, right(node), mid+1, rt);

        return lsum + rsum;
    }

    void printTree(){
        int i;
        rep(i,0,4*n){
            cout<<tree[i]<<" \n"[i==4*n-1];
        }
    }
};

int main(){
    SegmentTree sg;
    
    
    int i;
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        // sg.update(i, a[i]);
    }

    sg.build(a);

    cin>>q;
    rep(i,0,q){
        int type;
        cin>>type;
        if(type==0){
            int ind, val;
            cin>>ind>>val;
            sg.update(ind, val - a[ind]);
        }
        else if(type==1){
            int l, r;
            cin>>l>>r;
            cout<<sg.query(l,r)<<"\n";
        }
        else if(type==2)
            sg.printTree();
        
    }
}