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

int maxDiffRecur(Node* node,int &max_diff){
    if(!node) return INT_MAX;

    if(!node->left && !node->right) return node->data;

    int l_min = maxDiffRecur(node->left,max_diff);
    int r_min = maxDiffRecur(node->right,max_diff);

    int minn = min(l_min,r_min);

    max_diff = max(max_diff,node->data - minn);
    
    return min(node->data,minn);

}
 
/* Your are required to 
complete this method*/
int maxDiff(Node* root)
{
    if(!root) return INT_MIN;

    int max_diff = INT_MIN;

    maxDiffRecur(root,max_diff);

    return max_diff;
}
