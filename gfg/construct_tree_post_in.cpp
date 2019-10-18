#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int x){
      data=x;
      left = NULL;
      right = NULL;
  }
};

int n=6;
int postIndex = n-1;

Node* buildTree(int in[],int post[], int inStrt, int inEnd)
{
    if(inStrt == inEnd){
        return new Node(in[inStrt]);
    }

    int r = post[postIndex];
    Node* root = new Node(r);
    int pivot;
    for(int i=inStrt;i<=inEnd;i++)
        if(in[i]==r){
            pivot = i;
            break;
        }

    if(pivot!=inEnd){
        postIndex--;
        root->right = buildTree(in,post,pivot+1,inEnd);
    }
    else{
        root->right = NULL;
    }

    if(pivot!=inStrt){
        postIndex--;
        root->left = buildTree(in,post,inStrt,pivot-1);
    }
    else{
        root->left = NULL;
    }
    
    return root;
}

void postOrder(Node* root){
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}


int main(){
    cin>>n;
    Node* root = NULL;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    root=buildTree(a,b,0,n-1);
    preOrder(root);

}   