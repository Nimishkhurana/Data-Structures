#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int mSize;
    int n;
    int *arr;
    int *tree;

    int leftChild(int i){ return 2*i+1;}
    int rightChild(int i){ return 2*i+2;}

    int updateMin(int tree_ind, int tl, int tr, int qi, int diff);
    int queryMin(int tree_ind, int tl, int tr, int ql, int qr);


    public:
        SegmentTree(int *arr, int n);
        int constructTree(int tree_ind,int l, int r);
        int query(int l, int r);
        void updateValue(int ind , int new_val);
        void printTree(){
            cout<<"S="<<mSize<<endl;
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



int SegmentTree:: constructTree(int tree_ind,int l, int r){
    if(l==r) {
        tree[tree_ind] = arr[l];
        return arr[l];
    }

    int mid = l + (r-l)/2;

    int left_child = leftChild(tree_ind);
    int right_child = rightChild(tree_ind);

    int l_min = constructTree(left_child,l,mid);
    int r_min = constructTree(right_child,mid+1,r);

    tree[tree_ind] = min(l_min, r_min);
    return tree[tree_ind];
}

int SegmentTree:: queryMin(int tree_ind, int tl, int tr, int ql, int qr){
    if(tl>=ql && tr<=qr) return tree[tree_ind];

    if(tr<ql || tl>qr) return INT_MAX;

    int mid = tl + (tr-tl)/2;

    int left_child = leftChild(tree_ind);
    int right_child = rightChild(tree_ind);

    int l_min = queryMin(left_child,tl,mid,ql,qr);
    int r_min = queryMin(right_child,mid+1,tr,ql,qr);

    return min(l_min,r_min);
}

int SegmentTree:: updateMin(int tree_ind, int tl, int tr, int qi, int diff){
    if(qi < tl || qi > tr) return tree[tree_ind];

    if(tl == tr)
        tree[tree_ind] += diff;

    if(tl != tr){
        int mid = tl + (tr-tl)/2;

        int left_child = leftChild(tree_ind);
        int right_child = rightChild(tree_ind);

        int l_min = updateMin(left_child,tl,mid,qi,diff);
        int r_min = updateMin(right_child,mid+1,tr,qi,diff);

        tree[tree_ind] = min(l_min,r_min);
    }
    return tree[tree_ind];
}

int SegmentTree::query(int l, int r){
    return queryMin(0,0,n-1,l,r);
}

void SegmentTree::updateValue(int ind, int new_val){
    int diff = new_val - arr[ind];
    arr[ind] = new_val;

    updateMin(0,0,n-1,ind,diff);
}

int main(){
        int arr[] = {3,1,7,9,-5,100,5,15};
        int n = sizeof(arr)/sizeof(int);

        SegmentTree st(arr,n);
        cout<<endl<<"Min="<<st.query(0,2)<<endl;
        st.updateValue(4,10);
        cout<<endl<<"Min="<<st.query(0,2)<<endl;

        st.printTree();

}









