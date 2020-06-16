#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int mSize;
    int n;
    int *arr;
    int *tree;

    int leftChild(int i){ return 2*i+1;}
    int rightChild(int i){ return 2*i+2;}

    void updateSum(int node, int tl, int tr, int qi, int diff);
    int querySum(int node, int tl, int tr, int ql, int qr);


    public:
        SegmentTree(int *arr, int n);
        int constructTree(int node,int l, int r);
        int query(int l, int r);
        void updateValue(int ind , int new_val);
        void printTree(){
            for(int i=0;i<mSize;i++) cout<<tree[i]<<" ";
        };
};

SegmentTree::SegmentTree(int *arr, int n){
    this->n = n;
    this->arr = arr;
    int height = (int)(ceil(log2(n)));
    mSize = 2*(int)pow(2,height) - 1;
    tree = new int[mSize];
    memset(tree,0,mSize*sizeof(int));

    constructTree(0,0,n-1);

    printTree();
}


int SegmentTree:: constructTree(int node, int l, int r){
    if(l==r) {
        tree[node] = arr[l];
        return arr[l];
    }

    int mid = l + (r-l)/2;

    int left_child = leftChild(node);
    int right_child = rightChild(node);

    int l_sum = constructTree(left_child,l,mid);
    int r_sum = constructTree(right_child,mid+1,r);

    tree[node] = l_sum + r_sum;
    return tree[node];
}

int SegmentTree:: querySum(int node, int tl, int tr, int ql, int qr){
    if(tl>=ql && tr<=qr) return tree[node];

    if(tr<ql || tl>qr) return 0;

    int mid = tl + (tr-tl)/2;

    int left_child = leftChild(node);
    int right_child = rightChild(node);

    int l_sum = querySum(left_child,tl,mid,ql,qr);
    int r_sum = querySum(right_child,mid+1,tr,ql,qr);

    return l_sum + r_sum;
}

void SegmentTree:: updateSum(int node, int tl, int tr, int qi, int diff){
    if(qi < tl || qi > tr) return;

    tree[node] += diff;

    if(tl != tr){
        int mid = tl + (tr-tl)/2;

        int left_child = leftChild(node);
        int right_child = rightChild(node);

        updateSum(left_child,tl,mid,qi,diff);
        updateSum(right_child,mid+1,tr,qi,diff);
    }
}

int SegmentTree::query(int l, int r){
    return querySum(0,0,n-1,l,r);
}

void SegmentTree::updateValue(int ind, int new_val){
    int diff = new_val - arr[ind];
    arr[ind] = new_val;

    updateSum(0,0,n-1,ind,diff);
}

int main(){
        int arr[] = {5,3,1,7,9,0,2,1};
        int n = sizeof(arr)/sizeof(int);
       
        SegmentTree st(arr,n);
        // cout<<"\n";
        // st.printTree();
        // cout<<"\n";

        
        cout<<endl<<st.query(0,2)<<endl;
        st.updateValue(1,6);
        cout<<endl<<st.query(0,2)<<endl;

        st.printTree();
}









