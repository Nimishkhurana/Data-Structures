#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isNodeInTree(Node* root,int val){
    if(!root) return false;

    if(root->data == val) return true;

    return isNodeInTree(root->left,val) || isNodeInTree(root->right,val); 
}

Node * lcaRecur(Node* root ,int n1 ,int n2 ){
    if(!root) return NULL;

    if(root->data == n1 || root->data == n2) return root;

    Node* l = lcaRecur(root->left,n1,n2);
    Node* r = lcaRecur(root->right,n1,n2);

    if(l && r) return root;

    if(l) return l;
    if(r) return r;

    return NULL;
}

Node* lca(Node* root ,int n1 ,int n2){
    if(!root) return NULL;

    Node *lca = lcaRecur(root,n1,n2);

    if(!lca) return NULL;

    if(lca->data!=n1 && lca->data!=n2)
        return lca;
    
    if(lca->data == n1 && !isNodeInTree(root,n2)) cout<<n2<<" not found in tree. Returning reference to "<<n1<<"\n";
    if(lca->data == n2 && !isNodeInTree(root,n1)) cout<<n1<<" not found in tree. Returning reference to "<<n2<<"\n";

    return lca;
    
}