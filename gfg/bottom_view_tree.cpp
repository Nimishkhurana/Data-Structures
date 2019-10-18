#include<iostream>
using namespace std;

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; 
// Method that prints the bottom view.

void bottomViewRecur(Node* node,int x, int pos[]){
    if(!node) return;

    pos[x+50] = node->data;

    bottomViewRecur(node->left,x-1,pos);
    bottomViewRecur(node->right,x+1,pos);

}
void bottomView(Node *root)
{
    int pos[101]={-1};

    bottomViewRecur(root,0,pos);

    for(int i=0;i<100;i++){
        if(pos[i] != -1)
            cout<<pos[i]<<" ";
    }
}