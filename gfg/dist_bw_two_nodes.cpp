
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Should return minimum distance between a and b 
   in a tree with given root*/
   
int findDepth(Node* root, int val,int level){
    if(!root) return -1;
    
    if(root->data==val) return level;
    
    int l = findDepth(root->left,val,level+1);
    if(l!=-1) return l;
    else findDepth(root->right,val,level+1);
}

Node* lca_func(Node* root, int a, int b){
    if(!root) return NULL;
    
    if(root->data==a || root->data==b)
        return root;
    
    Node* l = lca_func(root->left,a,b);
    Node* r = lca_func(root->right,a,b);
    
    if(l && r) return root;
    if(l) return l;
    if(r) return r;
    return NULL;
}

int findDist(Node* root, int a, int b)
{
    Node* lca = lca_func(root,a,b);
    int d1 = findDepth(lca,a,0);
    int d2 = findDepth(lca,b,0);
    return d1+d2;
}