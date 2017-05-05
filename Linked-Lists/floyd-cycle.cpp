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
node* make(int data)
{
    node* a = new(node);
    a->data = data;
    return a;
}
int floyd(node* head)
{
    node* slow = head;
    node* fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}
int main()
{
    node *head = make(5);
    head->next = make(4);
    head->next->next = make(3);
    head->next->next->next = make(2);
    head->next->next->next->next = head;
    if(floyd(head))
        cout<<"Cycle";
    else
        cout<<"No Cycle";
}