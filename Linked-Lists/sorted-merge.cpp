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
node* merge(node* head1, node* head2)
{
    node* result = NULL;
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    if(head1->data <= head2->data)
    {
        result = head1;
        result->next = merge(head1->next,head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1,head2->next);
    }
    return result;
}
int main()
{
    node *head1 = NULL;
    push(&head1,7);
    push(&head1,5);
    push(&head1,3);
    push(&head1,2);
    push(&head1,1);
    node* head2 = NULL;
    push(&head2,15);
    push(&head2,14);
    push(&head2,8);
    push(&head2,6);
    push(&head2,4);
    push(&head2,2);
    push(&head2,0);
    node* result = merge(head1,head2);
    print(&result);
}