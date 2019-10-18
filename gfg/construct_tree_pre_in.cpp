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

int preIndex = 0;
Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    if(inStrt == inEnd){
        return new Node(in[inStrt]);
    }

    int r = pre[preIndex];
    Node* root = new Node(r);
    int pivot;
    for(int i=inStrt;i<=inEnd;i++)
        if(in[i]==r){
            pivot = i;
            break;
        }

    
    if(pivot!=inStrt){
        preIndex++;
        root->left = buildTree(in,pre,inStrt,pivot-1);
    }
    else{
        root->left = NULL;
    }

    if(pivot!=inEnd){
        preIndex++;
        root->right = buildTree(in,pre,pivot+1,inEnd);
    }
    else{
        root->right = NULL;
    }
    
    return root;
}

void postOrder(Node* root){
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    int n;
    cin>>n;
    Node* root = NULL;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    root=buildTree(a,b,0,n-1);
    postOrder(root);

}