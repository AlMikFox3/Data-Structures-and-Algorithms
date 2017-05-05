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
node* middle(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    node* brev = middle(head);
    cout<<brev->data;
}