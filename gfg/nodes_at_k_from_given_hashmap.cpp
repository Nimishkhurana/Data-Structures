#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

void populateHashMap(TreeNode* node,TreeNode* parent,unordered_map<TreeNode*,TreeNode*> &m){
    if(!parent || !node) return;

    m[node] = parent;

    populateHashMap(node->left,node,m);
    populateHashMap(node->right,node,m);
}

vector<int> distanceK( TreeNode* root, struct TreeNode* target, int K) {
    unordered_map<TreeNode*,TreeNode*> m;
    populateHashMap(root,NULL,m);

    queue<TreeNode*> q;
    unordered_map <TreeNode*,bool> visited;

    q.push(target);
    visited[target]=true;

    vector<int>res;

    while(K--){
        int size = q.size();
        while(size--){
            TreeNode* t = q.front();
            q.pop();

            if(t->left && !visited[t->left]){
                q.push(t->left);
                visited[t->left] = true;

            }  
            if(t->right && !visited[t->right]){
                q.push(t->right);
                visited[t->right]=true;
            }
            if(m[t] && !visited[m[t]]){
                q.push(m[t]);
                visited[m[t]]=true;
            }  
        }
    }

    while(!q.empty()){
        res.push_back(q.front()->val);
        q.pop();
    }

    return res;

}