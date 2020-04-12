#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int mSize;
    int n;
    int *arr;
    int *tree;
    int *lazy;

    int leftChild(int i){ return 2*i+1;}
    int rightChild(int i){ return 2*i+2;}

    void updateMin(int node, int tl, int tr, int ql,int qr, int diff);
    int queryMin(int node, int tl, int tr, int ql, int qr);


    public:
        SegmentTree(int *arr, int n);
        int constructTree(int node,int l, int r);
        int query(int l, int r);
        void updateValue(int l,int r, int new_val);
        void printTree(){
            cout<<"Tree: ";
            for(int i=0;i<mSize;i++) cout<<tree[i]<<" ";
            cout<<"\nLazy: ";
            for(int i=0;i<mSize;i++) cout<<lazy[i]<<" ";
        }
};

SegmentTree::SegmentTree(int *arr, int n){
    this->n = n;
    this->arr = arr;
    int height = (int)(ceil(log2(n)));
    mSize = 2*(int)pow(2,height) - 1;
    tree = new int[mSize];
    lazy = new int[mSize];

    memset(tree,0,mSize*sizeof(int));
    memset(lazy,0,mSize*sizeof(int));

    constructTree(0,0,n-1);

    cout<<"Initial Tree:-\n";
    printTree();

}


int SegmentTree:: constructTree(int node,int l, int r){
    if(l==r) {
        tree[node] = arr[l];
        return arr[l];
    }

    int mid = l + (r-l)/2;

    int l_child = leftChild(node);
    int r_child = rightChild(node);


    int l_min = constructTree(l_child,l,mid);
    int r_min = constructTree(r_child,mid+1,r);

    tree[node] = min(l_min, r_min);
    return tree[node];
}

int SegmentTree:: queryMin(int node, int tl, int tr, int ql, int qr){

    if(tl > tr) return INT_MAX;

    // Pending Updates
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(tl!=tr){
            int l_child = leftChild(node);
            int r_child = rightChild(node);

            lazy[l_child] += lazy[node];
            lazy[r_child] += lazy[node];
        }
        lazy[node] = 0;
    }

    // No overlap
    if(tr<ql || tl>qr) return INT_MAX;

    // Total Overlap
    if(tl>=ql && tr<=qr) return tree[node];

    // Partial Overlap
    if(tl!=tr){
        int mid = tl + (tr-tl)/2;

        int l_child = leftChild(node);
        int r_child = rightChild(node);

        int l_min = queryMin(l_child,tl,mid,ql,qr);
        int r_min = queryMin(r_child,mid+1,tr,ql,qr);

        return min(l_min,r_min);
    }
}

void SegmentTree:: updateMin(int node, int tl, int tr, int ql, int qr, int diff){

    if(tl > tr) return;

    // Pending Updates
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(tl!=tr){
            int l_child = leftChild(node);
            int r_child = rightChild(node);

            lazy[l_child] += lazy[node];
            lazy[r_child] += lazy[node];
        }
        lazy[node] = 0;
    }

    // Completely out of range
    if(qr < tl || ql > tr) return;

    // Completely in the range
    if(tl >= ql && tr <= qr){

        tree[node]+=diff;

        if(tl!=tr){
            int l_child = leftChild(node);
            int r_child = rightChild(node);

            lazy[l_child] += diff;
            lazy[r_child] += diff;
        }
        cout<<"\nTree node: "<<node<<endl;
        return;
    }
    
    //Partial Overlap
    int mid = tl + (tr-tl)/2;

    int l_child = leftChild(node);
    int r_child = rightChild(node);

    updateMin(l_child,tl,mid,ql,qr,diff);
    updateMin(r_child,mid+1,tr,ql,qr,diff);

    tree[node] = min(tree[l_child],tree[r_child]);
}

int SegmentTree::query(int l, int r){
    return queryMin(0,0,n-1,l,r);
}

void SegmentTree::updateValue(int l, int r, int diff){
    updateMin(0,0,n-1,l,r,diff);
}

int main(){
        int arr[] = {-1,2,4,1,7,1,3,2};
        int n = sizeof(arr)/sizeof(int);

        SegmentTree st(arr,n);
        st.updateValue(0,3,3);
        st.printTree();

        st.updateValue(0,3,1);
        st.printTree();

        st.updateValue(0,0,2);
        st.printTree();

        cout<<endl<<"Min="<<st.query(3,5)<<endl; 
        st.printTree(); 
}









