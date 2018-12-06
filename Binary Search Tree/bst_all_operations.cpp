#include<iostream>
#include<string>
using namespace std;

struct node{
    int info;
    node *left;
    node *right;
};

class BinaryTree{
    node *root;

    node * getNode(int data){
        node *temp = new node;
        temp->info = data;
        temp->left = NULL;
        temp ->right = NULL;
        return temp;
    }
    void caseA(int,node**,node**);
    void caseB(int,node**,node**);
    node* minValueNode(node*);

public:
    BinaryTree();
    void setRoot(node*);
    node* getRoot();
    node* insertInTree(node*,int);
    void traverseInorder(node*);
    void traversePreorder(node*);
    void traversePostorder(node*);
    int findDepth(node*);
    void peek();
    void printTree(node* ,int );
    void searchInTree(int,node**,node**);
    void deleteFromTree(int);
    friend bool compareTrees(node*,node*);
    void countNodes(node*,int&);
    void findMin(node*);
    void findMax(node*);
    void mirrorTree(node*);
    void countNodesAlternate(node*,bool,int&);
    void isPath(node*,int);
    node* deleteNode(node*,int);

};
    //Constructor to initialize root to NULL
    BinaryTree::BinaryTree(){
        root = NULL;
    }

    //Function to set Root of tree
    void BinaryTree:: setRoot(node *temp){
        root = temp;
    }

    //Function to get a root of tree
    node* BinaryTree:: getRoot(){
        return root;
    }

    //Inserts a node in tree
    node* BinaryTree:: insertInTree(node *T,int data){
        if(T == NULL){
            T = getNode(data);
        }
        else{
            if(data< T->info)
                T->left = insertInTree(T->left,data);
            else
                T->right = insertInTree(T->right,data);
        }
        return(T);
    }

    //InOrder traversal
    void BinaryTree::traverseInorder(node *p){
        if(p!=NULL){
            traverseInorder(p->left);
            cout<<p->info<<"    ";
            traverseInorder(p->right);
        }
    }

    //PreOrder Traversal
    void BinaryTree::traversePreorder(node *p){
        if(p!=NULL){
            cout<<p->info<<"    ";
            traversePreorder(p->left);
            traversePreorder(p->right);
        }
    }

    //PostOrder Traversal
    void BinaryTree::traversePostorder(node *p){
        if(p!=NULL){
            traversePostorder(p->left);
            traversePostorder(p->right);
            cout<<p->info<<"    ";
        }
    }

    //Prints info of root
    void BinaryTree:: peek(){
        if(root == NULL)
            cout<<"Root is NULL\n";
        else
            cout<<"Root->info = "<<root->info;
        }

    //Returns depth of tree
    int BinaryTree:: findDepth(node *p){
        if(p == NULL){
            return 0;
        }
        else{
            int l_depth = findDepth(p->left);
            int r_depth = findDepth(p->right);

            if(l_depth>r_depth)
                return l_depth + 1;
            return r_depth+1;
        }
    }

    //Prints tree
    void BinaryTree:: printTree(node* p,int space){
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

    //Searches a node and set its parent and location
    void BinaryTree:: searchInTree(int data,node **parent,node **loc){

        if(!root){
            *parent = *loc = NULL;
            return;
        }
        if(root->info == data){
            *parent = NULL;
            *loc = root;
            return;
        }
        *parent = NULL;
        *loc = root;
        while((*loc)!=NULL){
            if((*loc)->info == data){
                cout<<"Node found in the tree\n";
                return;
            }
            *parent = *loc;
            if(data >= (*loc)->info)
                *loc = (*loc)->right;
            else
                *loc = (*loc)->left;
        }
        if(!(*loc))
            cout<<"Node not found in tree\n";
    }

    //Iterative way to delete a node
    void BinaryTree:: deleteFromTree(int data){
        node *parent = NULL,*loc = NULL;
        searchInTree(data,&parent,&loc);
        if(parent)
            cout<<parent->info<<endl;
        cout<<loc->info<<endl;
        if(!parent && !loc)
            cout<<"Tree Empty\n";
        else if(!parent && loc)
            cout<<"Node to be deleted is at root\n";
        else if(parent && !loc)
            cout<<"Node to be deleted is not found in the tree\n";

        if((loc->left) && (loc->right)){
            cout<<"Case B\n";
            caseB(data,&parent,&loc);
            cout<<"Case B\n";
        }
        else{
            cout<<"Case A\n";
            if(!parent && loc){
                cout<"Hello\n";
                if(loc->left)
                    setRoot(loc->left);
                else
                    setRoot(loc->right);
                return;
            }
            caseA(data,&parent,&loc);
            cout<<"Case A\n";
        }
    }

    //Case for deletion with one or no child
    void BinaryTree:: caseA(int data,node **parent,node **loc){
         if(data > (*parent)->info){
            if(((*loc)->left == NULL) && ((*loc)->right == NULL))
                (*parent)->right = NULL;
            else if(((*loc)->left) && !((*loc)->right))
                (*parent)->right = (*loc)->left;
            else if(!((*loc)->left) && ((*loc)->right))
                (*parent)->right = (*loc)->right;
        }
        else{
            if(((*loc)->left == NULL) && ((*loc)->right == NULL))
                (*parent)->left = NULL;
            else if(((*loc)->left) && !((*loc)->right))
                (*parent)->left = (*loc)->left;
            else if(!((*loc)->left) && ((*loc)->right))
                (*parent)->left = (*loc)->right;
        }
    }

    //Case for deletion with two children
    void BinaryTree:: caseB(int data,node **parent,node **loc){
        node *ptr = (*loc)->right;
        node *save = *loc;                  //Finding InOrder successor of node to be deleted
        while(ptr->left){
            save = ptr;
            ptr = ptr->left;
        }
        cout<<"Successor = "<<ptr->info<<" and its Parent = "<<save->info<<endl;
        caseA(ptr->info,&save,&ptr);
        if(!(*parent)){
            setRoot(ptr);
        }
        else{
            if(data >= (*parent)->info)
                (*parent)->right = ptr;
            else
                (*parent)->left = ptr;
        }
        ptr->left = (*loc)->left;
        ptr->right = (*loc)->right;

    }

    //Function for checking if two trees are same or not i.e also comparing value of each node
    bool compareTrees(node *r1,node *r2){
        if((r1 && !r2) || (!r1 && r2))
            return false;
        if(!r1 && !r2)
            return true;
        else
            return (r1->info == r2->info) && compareTrees(r1->left,r2->left) && compareTrees(r1->right,r2->right);
    }

    //Count no. of nodes in tree
    void BinaryTree::countNodes(node *r,int &no_of_nodes){
         if(r!=NULL){
            countNodes(r->left,no_of_nodes);
            no_of_nodes++;
            countNodes(r->right,no_of_nodes);
        }
    }

    //Find minimum value in the tree
    void BinaryTree::findMin(node *r){
        if(r == NULL){
            cout<<"Tree Empty\n";
            return;
        }
        if(r->left == NULL){
            cout<<"Min = "<<r->info<<endl;
            return;
        }

        findMin(r->left);
    }

    //Find maximum value in the tree
    void BinaryTree::findMax(node *r){
        if(r == NULL){
            cout<<"Tree Empty\n";
            return;
        }
        if(r->right == NULL){
            cout<<"Max = "<<r->info<<endl;
            return;


        }
        findMax(r->right);
    }

    //Convert a tree to its mirror
    void BinaryTree:: mirrorTree(node *r){
        if(r == NULL )
            return;
        mirrorTree(r->right);
        mirrorTree(r->left);

        node *temp = r->right;
        r->right = r->left;
        r->left = temp;

    }

    //Function to find sum of no. of nodes in even levels
    void BinaryTree::countNodesAlternate(node *r,bool flag,int &Count){
        if(r==NULL)
            return;

        if(flag){
            Count++;
        }
        countNodesAlternate(r->left,!flag,Count);
        countNodesAlternate(r->right,!flag,Count);
    }

    //Function to check if path exists from root to any node with sum of nodes = 'sum'
    void BinaryTree::isPath(node *r,int sum){
        if(!r || sum<0){
            return ;
        }

        sum-=r->info;
        if(sum == 0){
            cout<<"Path exists:-\n";
        }
        isPath(r->left,sum);
        isPath(r->right,sum);
    }

    //Recursive function to delete a node from tree
node* BinaryTree:: deleteNode(node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->info)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->info)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->info = temp->info;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

//Utility function to find node with min value
node* BinaryTree:: minValueNode(node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}
/*
void BinaryTree:: secondLargestValue(){

    }
*/


int main(){
    int c,c2,depth,no_of_nodes=0;
    int data,sum;
    bool flag;

    BinaryTree tree;


    BinaryTree tree1,tree2;

    node *parent,*loc;
    parent = NULL;
    loc = tree.getRoot();


    do{
        cout<<"\n1.Insert\n2.Traverse InOrder\n3.Traverse PreOrder\n4.Traverse PostOrder\n5.Find Depth\n";
        cout<<"6.Print Tree\n7.Search\n8.Delete\n9.Compare two trees\n10.Count no. of nodes\n11.Count no. of nodes in even level\n12.Find Minimum\n";
        cout<<"13.Find Maximum\n14.Mirror Tree\n15.Check Path for Sum\n16.Delete Recursively\n0.Exit\n\nEnter your choice: ";
        cin>>c;
        switch(c){
       case 1:
           cout<<"Enter data to insert: ";
           cin>>data;
           tree.setRoot(tree.insertInTree(tree.getRoot(),data));
           break;
       case 2:
            tree.traverseInorder(tree.getRoot());
            break;
        case 3:
            tree.traversePreorder(tree.getRoot());
            break;
        case 4:
            tree.traversePostorder(tree.getRoot());
            break;
        case 5:
            depth = tree.findDepth(tree.getRoot());
            cout<<"Depth = "<<depth;
            break;
        case 6:
            tree.printTree(tree.getRoot(),0);
            break;
        case 7:
            cout<<"Enter data to search: ";
            cin>>data;
            tree.searchInTree(data,&parent,&loc);
            break;
        case 8:
            cout<<"Enter data to delete: ";
            cin>>data;
            tree.deleteFromTree(data);
            break;
        case 9:
            do{
            cout<<"1.Insert in Tree 1\n2.Insert in Tree 2\n3.Compare Tree1 and Tree2\n0.Exit\n";
            cin>>c2;
            switch(c2){
                case 1:
                    cout<<"Enter data to insert in Tree1: ";
                    cin>>data;
                    tree1.setRoot(tree1.insertInTree(tree1.getRoot(),data));
                    break;
                case 2:
                    cout<<"Enter data to insert in Tree2: ";
                    cin>>data;
                    tree2.setRoot(tree2.insertInTree(tree2.getRoot(),data));
                    break;
                case 3:
                    flag = compareTrees(tree1.getRoot(),tree2.getRoot());
                    if(flag)
                        cout<<"True\n";
                    else
                        cout<<"False\n";
                    break;
                case 0:
                    break;
                default:cout<<"\nEnter valid input\n";

                }
            }while(c2!=0);
            break;
        case 10:
             no_of_nodes=0;
             tree.countNodes(tree.getRoot(),no_of_nodes);
             cout<<"No. of nodes in tree = "<<no_of_nodes<<endl;
            break;
        case 11:
            no_of_nodes=0;
            tree.countNodesAlternate(tree.getRoot(),false,no_of_nodes);
            cout<<no_of_nodes<<endl;
            break;
        case 12:
            tree.findMin(tree.getRoot());
            break;
        case 13:
            tree.findMax(tree.getRoot());
            break;
        case 14:
            tree.mirrorTree(tree.getRoot());
            cout<<"Tree mirrored\n";
            break;
        case 15:
            cout<<"Enter Sum :";
            cin>>sum;
            tree.isPath(tree.getRoot(),sum);
            break;
        case 16:
            cout<<"Enter data to delete: ";
            cin>>data;
            tree.setRoot(tree.deleteNode(tree.getRoot(),data));
            break;
       case 0:
            break;
        }
    }while(c!=0);

}
