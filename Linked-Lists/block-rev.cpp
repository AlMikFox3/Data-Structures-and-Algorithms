#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node * next;
}node;
void print(node** head)
{
    node* curr = *head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<"\n";
}
void push(node ** head, int data)
{
    node* a = new(node);
    a->data = data;
    a->next = *head;
    *head = a;
}
node* block_rev(node* head, int k)
{
    node * curr = head;
    node * prev = NULL;
    node * nxt = NULL;
    int count = 0;
    while(curr && count<k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    if(nxt!=NULL)
        head->next = block_rev(nxt,k);
    return prev;
}
int main()
{
    node *head = NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    print(&head);
    node* brev = block_rev(head,2);
    print(&brev);
}