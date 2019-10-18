#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int mSize;
    int n;
    int *arr;
    int *tree;

    int leftChild(int i){ return 2*i+1;}
    int rightChild(int i){ return 2*i+2;}

    int updateXOR(int tree_ind, int tl, int tr, int qi, int diff);
    int queryXOR(int tree_ind, int tl, int tr, int ql, int qr);


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


    int l_xor = constructTree(left_child,l,mid);
    int r_xor = constructTree(right_child,mid+1,r);

    tree[tree_ind] = l_xor ^ r_xor;
    return tree[tree_ind];
}

int SegmentTree:: queryXOR(int tree_ind, int tl, int tr, int ql, int qr){
    if(tl>=ql && tr<=qr) return tree[tree_ind];

    if(tr<ql || tl>qr) return 0;

    int mid = tl + (tr-tl)/2;

    int left_child = leftChild(tree_ind);
    int right_child = rightChild(tree_ind);

    int l_xor = queryXOR(left_child,tl,mid,ql,qr);
    int r_xor = queryXOR(right_child,mid+1,tr,ql,qr);

    return l_xor ^ r_xor;
}

int SegmentTree:: updateXOR(int tree_ind, int tl, int tr, int qi, int diff){
    if(qi < tl || qi > tr) return tree[tree_ind];

    if(tl == tr)
        tree[tree_ind] += diff;

    if(tl != tr){
        int mid = tl + (tr-tl)/2;

        int left_child = leftChild(tree_ind);
        int right_child = rightChild(tree_ind);

        int l_xor = updateXOR(left_child,tl,mid,qi,diff);
        int r_xor = updateXOR(right_child,mid+1,tr,qi,diff);

        tree[tree_ind] = l_xor ^ r_xor;
    }
    return tree[tree_ind];
}

int SegmentTree::query(int l, int r){
    return queryXOR(0,0,n-1,l,r);
}

void SegmentTree::updateValue(int ind, int new_val){
    int diff = new_val - arr[ind];
    arr[ind] = new_val;

    updateXOR(0,0,n-1,ind,diff);
}

int main(){
        int arr[] = {6,5,7,9,5,100,5,15};
        int n = sizeof(arr)/sizeof(int);

        SegmentTree st(arr,n);
        cout<<endl<<"XOR="<<st.query(0,1)<<endl;
        st.updateValue(0,7);
        cout<<endl<<"XOR="<<st.query(0,1)<<endl;

        st.printTree();

}









