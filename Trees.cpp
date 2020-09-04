#include <bits/stdc++.h>
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

node * buildTree()
{
    cout<<"Enter the data\n";
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node * temp = new node (d);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

void preOrder(node * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node * root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrder(node * root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int countNodes(node * root)
{
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int height(node * root)
{
    if(root==NULL)
        return -1;
       int h1 = height(root->left);
       int h2 = height(root->right);
       int ans = max(h1,h2);
       return (ans+1);
}

void levelOrderPrint(node * root)
{
    queue<node *> a;
    a.push(root);

    while(!a.empty())
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

int main(){

    node *root;
    //root = buildTree();

    levelOrderInput(root);

    cout<<endl<<"PreOrder -> ";
    preOrder(root);
    cout<<endl<<"InOrder -> ";
    inOrder(root);
    cout<<endl<<"PostOrder ->";
    postOrder(root);
    cout<<endl<<"LevelOrder -> ";
    levelOrderPrint(root);
    cout<<endl;

    cout<<"No of nodes = "<<countNodes(root)<<endl;
    cout<<"Height of tree = "<<height(root)<<endl;

    return 0;
}
