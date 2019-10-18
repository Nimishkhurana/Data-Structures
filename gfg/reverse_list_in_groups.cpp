#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
    
}*head;

node *reverse(struct node *head, int k)
{ 
    node* curr=head, *prev=NULL, *last=NULL;
    while(curr){
        int count=0;
        node *h = curr;
        // h->next=NULL;
        while(curr && count<k){
            node* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
            if(next)
            next = next->next;
            count++;
        }
        if(!last){
            head = prev;
        }
        else{
            last->next = prev;
        }
        last = h;
        prev = NULL;
    }
    return head;

}

node *reverse2 (struct node *head, int k)
{ 
    node* sprev=NULL,*prev=NULL;
    int count=1;
    node*c=head,*p=NULL,*n=head->next;
    while(c){
        if(count%k==1){
            sprev = prev;
            prev = c;
            n = c->next;
            // c->next = p;
            p = c;
            c = n;
            continue;
        }
        if(count%k==0){
            if(sprev){
                sprev->next = c;
            }
            else{
                head=c;
            }
        } 
        else{
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        count++;
    }
    return head;
}