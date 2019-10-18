#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

void printLeafNodes(Node* root){
    if(!root)
        return;
    
    printLeafNodes(root->left);

    if(!root->left && !root->right)
        cout<<root->data<<" ";
    
    printLeafNodes(root->right);
}

void printLeftBoundary(Node* root){
    if(!root)
        return;
    
    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundary(root->left);
    }

    else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root){
    if(!root)
        return;
    
    if(root->right){
        printRightBoundary(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printRightBoundary(root->left);
        cout<<root->data<<" ";
    }

}

void printBoundary(Node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeafNodes(root);
    printRightBoundary(root->right);
}

// A utility function to create a Node 
Node* newNode(int data) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
  
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us construct the tree given in the above diagram 
    struct Node* root = newNode(20); 
    root->left = newNode(8); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 
    root->right = newNode(22); 
    root->right->right = newNode(25); 
  
    printBoundary(root); 
  
    return 0; 
} 