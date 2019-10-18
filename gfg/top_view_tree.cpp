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

void fillMap(Node* node,int dist,int depth, map<int,pair<int,int>> &m){
    if(!node) return;

    if(m.find(dist) == m.end() || m[dist].second > depth)
        m[dist] = {node->data,depth};
    
    fillMap(node->left,dist-1,depth+1,m);
    fillMap(node->right,dist+1,depth+1,m);
}

void topView(Node* root){
    map<int,pair<int,int>> m;
    fillMap(root,0,0,m);

    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" ";
}