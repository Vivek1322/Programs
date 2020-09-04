/*
1. Using recursion O(N^2)
2. Use hash table to store the index of the inorder traversal. This would reduce the search time to O(1) and hence the complexity of code to O(N)
*/


#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node * left;
    node * right;
    node(char c)
    {
        data = c;
        left = right = NULL;
    }
};

node * buildTree(char * in, char * pr, int in_start, int in_end, int pr_start, int pr_end)
{
    ///Base case
    if(in_start>in_end || pr_start>pr_end)
        return NULL;
    if(in_start == in_end)
    {
        node * root = new node(in[in_start]);
        return root;
    }

    ///Recursive case
    int i = in_start;
    while(in[i]!=pr[pr_start])
        i++;
    int n = i-in_start;
    node * root = new node(pr[pr_start]);
    root->left = buildTree(in, pr, in_start, i-1, pr_start+1, pr_start+n);
    root->right = buildTree(in, pr, i+1, in_end, pr_start+n+1, pr_end);
    return root;
}

node * buildTree2(char * in, char * po, int in_start, int in_end, int po_start, int po_end)
{
    ///Base case
    if(po_start>po_end || in_start>in_end)
        return NULL;
    if(in_start == in_end)
    {
        node * root = new node (in[in_start]);
        return root;
    }

    ///Recursive case
    int i = in_start;
    while(in[i]!=po[po_end])
        i++;
    int n = i-in_start;
    node * root = new node (po[po_end]);
    root->left = buildTree2(in, po, in_start, i-1, po_start, po_start+n-1);
    root->right = buildTree2(in, po, i+1, in_end, po_start+n, po_end-1);
    return root;

}

void levelOrderPrint(node * root)
{
    queue<node *> a;
    a.push(root);
    a.push(NULL);

    while(!a.empty())
    {
        if(a.front()==NULL)
        {
            a.pop();
            cout<<endl;
            if(!a.empty())
            {
                a.push(NULL);
                continue;
            }
        }
        else
        {
            node * f = a.front();
            a.pop();
            if(f->left)
                a.push(f->left);
            if(f->right)
                a.push(f->right);
            cout<<f->data<<" ";
        }
    }
}

int main()
{
    cout<<"Enter the total number of nodes -> ";
    int n;
    cin>>n;

    char * in = new char[n];
    char * pr = new char [n];
    char * po = new char [n];

    cout<<"Enter the inorder traversal -> ";
    for(int i=0; i<n; i++)
        cin>>in[i];

    cout<<"Enter the preorder traversal -> ";
    for(int i=0; i<n; i++)
        cin>>pr[i];

    cout<<"Enter the postorder traversal -> ";
    for(int i=0; i<n; i++)
        cin>>po[i];

    node * root1 = buildTree(in, pr, 0, n-1, 0, n-1);
    node * root2 = buildTree2(in, po, 0, n-1, 0, n-1);

    levelOrderPrint(root1);
    cout<<endl;
    levelOrderPrint(root2);
    cout<<endl;

    return 0;
}

