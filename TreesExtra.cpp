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

void printAtLevel(node * root, int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data;
        return;
    }
    printAtLevel(root->left, k-1);
    printAtLevel(root->right, k-1);
}

int main()
{
    node * root = NULL;
    levelOrderInput(root);
    cout<<endl;
    cout<<"Level order print of the tree is as follows:- "<<endl;
    levelOrderPrint(root);

    return 0;
}
