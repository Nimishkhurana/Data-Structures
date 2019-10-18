// One simple way can be to inorder traversal and keep comparing current node value with prev node. If less then return false else recur.

// Another solution based on that values in left subtree can be max node->value-1 and in right subtree min node->value+1.
// We keep  narrowing max and min.

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool isBSTRecur(Node* root, Node* l, Node* r){
    if(!root) return true;

    if(l && root->data < l->data) return false;

    if(r && root->data > r->data) return false;

    return isBSTRecur(root->left,l,root) && isBSTRecur(root->right,root,r);

}

bool isBST(Node* root){
    return isBSTRecur(root,NULL,NULL);
}
