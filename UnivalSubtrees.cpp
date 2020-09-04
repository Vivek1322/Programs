
#include<bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node * left;
    node * right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};

class myPair
{
public:
    bool isUnival;
    int count;
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

myPair univalUtil(node * root)
{
    myPair p;
    if(root==NULL)
    {
        p.count = 0;
        p.isUnival = true;
        return p;
    }
    if(root->left==NULL && root->right==NULL)
    {
        p.count = 1;
        p.isUnival = true;
        return p;
    }
    else if(root->right==NULL && root->left!=NULL)
    {
        myPair left = univalUtil(root->left);

        if(root->data == root->left->data && left.isUnival)
        {
            p.count = left.count + 1;
            p.isUnival = true;
        }
        else
        {
            p.count = left.count;
            p.isUnival = false;
        }
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        myPair right = univalUtil(root->right);

        if(root->data == root->right->data && right.isUnival)
        {
            p.count = right.count + 1;
            p.isUnival = true;
        }
        else
        {
            p.count = right.count;
            p.isUnival = false;
        }
    }
    else
    {
        myPair left = univalUtil(root->left);
        myPair right = univalUtil(root->right);

        if(root->data == root->right->data && right.isUnival && root->data == root->left->data && left.isUnival)
        {
            p.count = left.count + right.count + 1;
            p.isUnival = true;
        }
        else
        {
            p.count = left.count + right.count;
            p.isUnival = false;
        }
    }
    return p;
}

int unival(node * root)
{
    myPair p = univalUtil(root);
    return p.count;
}

int main()
{
    node * root;
    levelOrderInput(root);
    cout<<endl;
    cout<<"Level order print of the tree is as follows:- "<<endl;
    levelOrderPrint(root);

    cout<<"Number of unival subtrees is "<<unival(root)<<endl;

    return 0;
}
