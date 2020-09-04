#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node * left;
     node * right;
     node (int d)
     {
         data = d;
         right = left = NULL;
     }
};

node * arrayToBST(int * a, int s, int e)
{
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    node * root = new node(a[mid]);
    root->left = arrayToBST(a, s, mid);
    root->right = arrayToBST(a, mid+1, e);
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
    cout<<"Enter size of array"<<endl;
    int n;
    cin>>n;
    int *a = new int(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    node *root = arrayToBST(a, 0, n-1);
    levelOrderPrint(root);


    return 0;
}
