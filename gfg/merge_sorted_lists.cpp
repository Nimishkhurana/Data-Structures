#include<iostream>
using namespace std;


struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to merge the two sorted linked lists
// head1, head2: head of the two sorted linked lists
Node* sortedMerge(Node* head1,   Node* head2)
{
    
    Node* dummy = new Node(0);
    Node* tail = dummy;

    Node* h1=head1, *h2=head2;

    while (h1 || h2)
    {
        if(!h1){
            tail->next = h2;
            h2 = h2->next;
        }
           
        else if(!h2){
            tail->next = h1;
            h1=h1->next;
        }
            
        else{
            if(h1->data <= h2->data){
                tail->next = h1;
                h1 = h1->next;
            }
            else{
                tail->next = h2;
                h2 = h2->next;
            }
        }
        tail = tail->next;     
    }
    
    return dummy->next;
}

void push(Node** head_ref, int new_data)  
{  
    /* allocate node */
    Node* new_node = new Node(new_data); 
  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  

/* Function to print nodes in a given linked list */
void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<" ";  
        node = node->next;  
    }  
}  

int main()  
{  
    /* Start with the empty list */
    Node* res = NULL;  
    Node* a = NULL;  
    Node* b = NULL;  
  
    /* Let us create two sorted linked lists   
    to test the functions  
    Created lists, a: 5->10->15, b: 2->3->20 */
    push(&a, 15);  
    push(&a, 10);  
    push(&a, 5);
    push(&a,1);  
  
    push(&b, 20);  
    push(&b, 3);  
    push(&b, 2);  
  
    /* Remove duplicates from linked list */
    res = sortedMerge(a, b);  
  
    cout << "Merged Linked List is: \n";  
    printList(res);  
  
    return 0;  
} 