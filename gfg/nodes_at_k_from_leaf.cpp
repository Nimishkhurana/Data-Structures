#include<iostream>
#include<cmath>
using namespace std;

int MAX_HEIGHT = 1000;

struct Node
{
	int key;
	Node *left, *right;
};

Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 

void fun(Node *node,int path[],bool visited[],int currLevel,int &count, int k){
    if(!node)
        return;
    path[currLevel] = node->key;

    visited[currLevel] = false;

    if(!node->left && !node->right){
        int t = currLevel-k;
        if(t>=0 && !visited[t]){
            visited[t] = true;
            count++;    
            cout<<path[t]<<" ";
        }
        return;
    }
    // currLevel++;
    
    fun(node->left,path,visited,currLevel+1,count,k);
    fun(node->right,path,visited,currLevel+1,count,k);

}

// gurpreet's logic incorrect ans
// int fun2(Node* node, int k, int &count){
//     if(!node) return INT_MAX;
//     if(!node->left && !node->right) return 0;

//     int val = 1 + min(fun2(node->left,k,count),fun2(node->right,k,count));

//     if(val == k){
//         count++;
//         cout<<node->key<<" ";
//     }
//     return val;

// }


int printKDistantfromLeaf(Node* node, int k)
{
    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    int currLevel=0,count=0;
    
    fun(node,path,visited,currLevel,count,k);
   return count;
}

int main() 
{ 
    // Let us create binary tree given in the above example 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    // cout << "Nodes at distance 2 are: "; 
    // cout<<endl<<printKDistantfromLeaf(root, 1); 
    int count = 0;
    fun2(root,3, count);
    cout<<count;
  
    return 0; 
} 