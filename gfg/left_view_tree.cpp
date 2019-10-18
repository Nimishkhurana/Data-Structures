#include<bits/stdc++.h>
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

void leftViewRecur(Node* node,int depth, unordered_set<int> &s){
    if(!node) return;

    if(s.find(depth) == s.end()){
        cout<<node->data<<" ";
        m.insert(depth);
    }

    
    
    leftViewRecur(node->left,depth+1,s);
    leftViewRecur(node->right,depth+1,s);

    
}

void leftView(Node* root){
    unordered_set<int> m;
    leftViewRecur(root,0,m);

}