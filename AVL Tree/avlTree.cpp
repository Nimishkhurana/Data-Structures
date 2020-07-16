#include<iostream>
using namespace std;


struct node{
    node *left;
    node *right;
    int info;
    int height;
};

class AVLTree{
    node *root;

    node* getNode(int);

    int getHeight(node*);
    void updateHeight(node*);

    int getBalance(node *);

    node* rotationForLL(node *);
    node* rotationForRR(node *);
    node* rotationForLR(node *);
    node* rotationForRL(node *);

    node* balanceTree(node*,int);
    node* minValueNode(node*);


public:
    AVLTree(){root = NULL;}
    void traversePreorder(node*);
    node* insertInAVLTree(node*,int);
    node *getRoot();
    void setRoot(node*);
    void printTree(node*,int);
    void searchInTree(int,node**,node**);
    node* deleteNode(node*,int);

};

int findMax(int a, int b)
{
    return (a > b)? a : b;
}

node* AVLTree:: getNode(int data){
        node *temp = new node;
        temp->info = data;
        temp->left = NULL;
        temp ->right = NULL;
        temp->height = 1;
        return temp;
}

void AVLTree::traversePreorder(node *p){
        if(p!=NULL){
            cout<<p->info<<"    ";
            traversePreorder(p->left);
            traversePreorder(p->right);
        }
}

int AVLTree::getHeight(node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

void AVLTree::updateHeight(node *N){
    N->height = 1 + findMax(getHeight(N->left),getHeight(N->right));
}

int AVLTree::getBalance(node *N){
    if (N == NULL)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

node* AVLTree::rotationForLL(node* N){
    node *x = N->left;
    node *y = x->right;

    x->right = N;
    N->left = y;

    return(x);
}

node* AVLTree::rotationForRR(node* N){
    node *x = N->right;
    node *y = x->left;

    x->left = N;
    N->right = y;

    return(x);
}

node* AVLTree::rotationForLR(node* N){
    N->left = rotationForRR(N->left);
    return rotationForLL(N);
}

node* AVLTree::rotationForRL(node* N){
    N->right = rotationForLL(N->right);
    return rotationForRR(N);
}

node* AVLTree:: insertInAVLTree(node *T,int data){
    if(T == NULL){
        T = getNode(data);
    }
    else{
        if(data< T->info)
            T->left = insertInAVLTree(T->left,data);
        else
            T->right = insertInAVLTree(T->right,data);
    }

    return(balanceTree(T,data));
}

node* AVLTree:: balanceTree(node* T, int data){
    updateHeight(T);
    int balance = getBalance(T);

    if (balance > 1){
         if(data < T->left->info)
            return rotationForLL(T);
        else
            return rotationForLR(T);
    }
    else if(balance < -1){
        if(data > T->right->info)
            return rotationForRR(T);
        else
            return rotationForRL(T);
    }

    return T;
    }

node* AVLTree::getRoot(){
    return root;
}

void AVLTree::setRoot(node* N){
    root = N;
}

 void AVLTree:: printTree(node* p,int space){
        if(p==NULL)
            return;
        space += 4;
        printTree(p->right,space);
        cout<<endl;
        for (int i = 2; i < space; i++)
            cout<<" ";
        cout<<p->info<<endl;

        printTree(p->left,space);
}


node* AVLTree:: deleteNode(node* T, int key)
{
    if (T == NULL) return T;

    if (key < T->info)
        T->left = deleteNode(T->left, key);

    else if (key > T->info)
        T->right = deleteNode(T->right, key);

    else
    {
        if( (T->left == NULL) || (T->right == NULL) )
        {
           if (T->left == NULL){
            node *temp = T->right;
            delete(T);
            T = temp;
            }

            else if (T->right == NULL){
            node *temp = T->left;
            delete(T);
            T = temp;
            }
            else if(!T->right and !T->left){
            delete(T);
            T = NULL;
            }
        }
        else if (T->left && T->right ) {
            node* temp = minValueNode(T->right);
            T->info = temp->info;
            T->right = deleteNode(T->right, temp->info);
            cout<<"deleted\n";
        }
    }
    if(T == NULL)
        return T;

    updateHeight(T);
    int balance = getBalance(T);

    if (balance > 1){
         if(key < T->left->info)
            return rotationForLL(T);
        else
            return rotationForLR(T);
    }
    else if(balance < -1){
        if(key > T->right->info)
            return rotationForRR(T);
        else
            return rotationForRL(T);
    }
    return(T);

}
node* AVLTree:: minValueNode(node* N)
{
    while (N->left != NULL)
        N = N->left;

    return N;
}

int main(){
    AVLTree tree;
    int c,data;
    node* root;

    do{
        cout<<"\n1.Insert\n2.Delete\n3.Traverse PreOrder\n4.Print Tree\n0.Exit\n\nEnter your choice: ";
        cin>>c;

        switch(c){
    case 1:
        cout<<"Enter data to insert: ";
        cin>>data;
        root = tree.insertInAVLTree(tree.getRoot(),data);
        tree.setRoot(root);
        break;
    case 2:
        cout<<"Enter data to delete: ";
        cin>>data;
        tree.setRoot(tree.deleteNode(tree.getRoot(),data));
        break;
    case 3:
        tree.traversePreorder(tree.getRoot());
        cout<<endl;
        break;
    case 4:
        tree.printTree(tree.getRoot(),0);
        break;
        }
    }while(c!=0);

}
