#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

};

//    given data and NULL left and right pointers. */
Node* newNode(int data) 
{ 
    Node* node = new Node;
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 

 void inOrder(Node* root, vector<int> &in){
    if(!root) return;

    inOrder(root->left,in);
    in.push_back(root->data);
    inOrder(root->right,in);
}

void swapIncorrect(Node* root,int first, int second){
    if(!root) return;

    if(root->data == first)
        root->data = second;
    else if(root->data == second)
        root->data = first;

    swapIncorrect(root->left,first,second);
    swapIncorrect(root->right,first,second);

}

Node* correctBST(Node* root){
    vector<int> in;

    inOrder(root,in);

    cout<<"\n";
    for(auto x:in) cout<<x<<" ";
    cout<<"\n";

    int first,second;
    bool flag=false;
    // cout<<in.size();

    for(int i=0;i<in.size();i++){
        // cout<<i<<" ";;

        if(!flag && in[i]>in[i+1]){
            // cout<<"Found";
            first = in[i];
            flag = true;
            i++;
        }   
        else if(flag && in[i] < in[i-1]){
                second = in[i];
                break;
        }   
    }
    if(flag){
        cout<<"First="<<first<<"  Second="<<second<<"\nFixing\n";
        swapIncorrect(root,first,second);
    }
        
    return root;
   
}

void printInorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout<<node->data<<" "; 
    printInorder(node->right); 
} 


/* Driver program to test above functions*/
int main() 
{ 
    /*   6 
        /  \ 
       10    2 
      / \   / \ 
     1   3 7  12 
     10 and 2 are swapped 
    */
  
    Node *root = newNode(6); 
    root->left        = newNode(10); 
    root->right       = newNode(2); 
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->right = newNode(12); 
    root->right->left = newNode(7); 
  
    cout<<"Inorder Traversal of the original tree \n"; 
    printInorder(root); 
  
    correctBST(root); 
  
    cout<<"\nInorder Traversal of the fixed tree \n"; 
    printInorder(root); 
  
    return 0; 
} 