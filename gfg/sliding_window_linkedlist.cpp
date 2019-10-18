#include<iostream>
using namespace std;

// Structure of a Node 
struct Node { 
    int data; 
    Node* next; 
}; 
  
// Function to create new Node 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->next = NULL; 
    node->data = data; 
    return node; 
} 

int maxSumOfKelements(Node* head,int k){
    Node* left = head;
    Node* right = head;

    int currSum=0,maxSum=0;
    for(int i=0;i<k;i++){
        currSum+=right->data;
        right = right->next;
    }
    maxSum = currSum;

    while(right){
        currSum -= left->data;
        currSum += right->data;

        maxSum = max(maxSum,currSum);

        left = left->next;
        right = right->next;
    }

    return maxSum;
}

// Driver code 
int main() 
{ 
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
    head->next->next->next->next->next = newNode(6); 
  
    int k = 5; 
  
    cout << maxSumOfKelements(head, k); 
  
    return 0; 
} 

