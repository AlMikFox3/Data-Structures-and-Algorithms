#include<iostream>
using namespace std;
typedef struct node{
    int data;
    struct node * next;
}node;
node* makenode(int data)
{
    node* a = new(node);
    if(a){
        a->data = data;
        a->next = NULL;
    }
    else{
        cout<<"Memory not allocated for node!";
    }
    return a;
}
node* buildll(node ** head)
{
    int v;
    node* curr,*q;
    cout<<"Enter value :";
    cin>>v;
    *head = makenode(v);
    curr = *head;
    while(1){
        cout<<"Enter value :";
        cin>>v;
        if(v!=-1){
            q = makenode(v);
            curr->next = q;
            curr = curr->next;
        }
        else break;
    }
}
void inspos(node ** head, int pos, int data)
{
    node* p, *q, *curr;
    int k =1;
    curr = makenode(data);
    p = *head;
    if(pos == 1)
    {
        curr->next = *head;
        *head = curr;
    }
    else{
        while(k<pos && p!= NULL)
        {
            k++;
            q = p;
            p = p->next;
        }
        curr->next = p;
        q->next = curr;
    }
}
void delpos(node ** head, int pos)
{
    node *p, *q, *curr;
    int k =1;
    p = *head;
    if(pos == 1)
    {
        p = p->next;
        delete(p);
    }
    else{
        while(k<pos && p->next!=NULL){
            q = p;
            p = p->next;
            k++;
        }
        q->next = p->next;
        delete(p);
    }

}
void printll(node ** head)
{
    node* curr = *head;
    while(curr != NULL)
    {
        cout<<curr->data<<" --> ";
        curr = curr->next;
    }
    cout<<endl;
}
int main()
{
    node *head;
    buildll(&head); // Tried the following example for 9 elements
    printll(&head);
    inspos(&head, 2, 13);
    printll(&head);
    inspos(&head, 11, 13);
    printll(&head);
    delpos(&head, 11);
    printll(&head);
    delpos(&head, 9);
    printll(&head);
    return 0;
}
