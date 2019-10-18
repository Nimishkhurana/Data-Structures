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

void fillMap(Node* node,int depth, map<int,int> &m){
    if(!node) return;
    
    fillMap(node->left,depth+1,m);
    fillMap(node->right,depth+1,m);

    m[depth] = node->data;
}

void rightView(Node* root){
    map<int,int> m;
    fillMap(root,0,m);

    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
}