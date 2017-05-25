#include <bits/stdc++.h>
using namespace std;
const int LEAF_LEN = 2;
 
// Rope structure
class Rope
{
public:
    Rope *left, *right, *parent;
    char *str;
    int lCount;
};

void createRopeStructure(Rope *&node, Rope *par,
                         char a[], int l, int r)
{
    Rope *tmp = new Rope();
    tmp->left = tmp->right = NULL;
    tmp->lCount = (r-l)/2;
    tmp->parent = par;
    if ((r-l) > LEAF_LEN)
    {
        tmp->str = NULL;
        node = tmp;
        int m = (l + r)/2;
        createRopeStructure(node->left, node, a, l, m);
        createRopeStructure(node->right, node, a, m+1, r);
    }
    else
    {
        node = tmp;
        int j = 0;
        tmp->str = new char[LEAF_LEN];
        for (int i=l; i<=r; i++)
            tmp->str[j++] = a[i];
    }
}
 
void printstring(Rope *r)
{
    if (r==NULL)
        return;
    if (r->left==NULL && r->right==NULL)
        cout << r->str;
    printstring(r->left);
    printstring(r->right);
}

void concatenate(Rope *&root3, Rope *root1, Rope *root2, int n1)
{
    
    Rope *tmp = new Rope();
    tmp->parent = NULL;
    tmp->left = root1;
    tmp->right = root2;
    root1->parent = root2->parent = tmp;
    tmp->lCount = n1;
    tmp->str = NULL;
    root3 = tmp;
}

int main()
{
 
    Rope *root1 = NULL;
    char a[] =  "Hi I am Sasmit. ";
    int n1 = sizeof(a)/sizeof(a[0]);
    createRopeStructure(root1, NULL, a, 0, n1-1);
 
    Rope *root2 = NULL;
    char b[] =  " How you doing.";
    int n2 = sizeof(b)/sizeof(b[0]);
    createRopeStructure(root2, NULL, b, 0, n2-1);
 
    Rope *root3 = NULL;
    concatenate(root3, root1, root2, n1);

    printstring(root3);
    cout << endl;
    return 0;
}