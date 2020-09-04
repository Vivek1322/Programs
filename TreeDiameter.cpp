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
        left=right=NULL;
    }
};

class myPair
{
public:
    int h, d;
};

void levelOrderInput(node *&root)
{
    cout<<"Enter the root node."<<endl;
    int d;
    cin>>d;
    root = new node(d);
    queue<node *> a;
    a.push(root);

    while(!a.empty())
    {
        node * f = a.front();
        a.pop();

        int b, c;
        cout<<"Enter the children of "<<f->data<<endl;
        cin>>b>>c;

        if(b!=-1)
        {
            f->left = new node (b);
            a.push(f->left);
        }
        else
        {
            f->left = NULL;
        }
        if(c!=-1)
        {
            f->right = new node (c);
            a.push(f->right);
        }
        else
        {
            f->right = NULL;
        }
    }
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

int height(node * root)
{
    if(root==NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int ans = max(h1, h2);
    return 1+ans;
}

int diameter(node *root)
{
    if(root==NULL)
        return 0;
    int h = height(root->left)+height(root->right);
    int d1 = diameter(root->left);
    int d2 = diameter(root->right);

    return max(max(d1, d2), h);
}

myPair diameterFast(node *root)
{
    myPair p;

    if(root==NULL)
    {
        p.h = 0;
        p.d = 0;
        return p;
    }

    myPair left = diameterFast(root->left);
    myPair right = diameterFast(root->right);
    int d1 = right.d;
    int d2 = left.d;
    int h1 = right.h;
    int h2 = left.h;
    p.h = 1+max(h1, h2);
    p.d = max(max(d1, d2), h1+h2);
    return p;
}

int main()
{
    node *root;
    levelOrderInput(root);
    cout<<"\nLevel order print ->\n";
    levelOrderPrint(root);

    cout<<"\nHeight of the tree = "<<height(root);
    cout<<"\nDiameter of the tree = "<<diameter(root);
    myPair p = diameterFast(root);
    cout<<"\nHeight of the tree = "<<p.h;
    cout<<"\nDiameter of the tree = "<<p.d;
    return 0;
}
