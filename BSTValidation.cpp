#include <bits/stdc++.h>
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

class myPair
{
public:
    int height;
    bool balance;
};

int BSTheight(node * root)
{
    if(root==NULL)
        return 0;
    return 1+max(BSTheight(root->left), BSTheight(root->right));
}

myPair isBalanced(node * root)
{
    myPair s;
    if(root==NULL)
    {
        s.height = 0;
        s.balance = true;
        return s;
    }
    myPair left = isBalanced(root->left);
    myPair right = isBalanced(root->right);

    s.height = 1+max(left.height, right.height);
    if(left.balance && right.balance && abs(right.height-left.height)<=1)
        s.balance = true;
    else
        s.balance = false;
    return s;
}

bool isBST(node * root, int min=INT_MIN, int max=INT_MAX)
{
    if(root==NULL)
        return true;
    if(root->data>=min && root->data<max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max))
        return true;
    return false;
}

node * insertInBST(node *root, int d)
{
    if(root==NULL)
    {
        root = new node(d);
        return root;
    }
    if(d<=root->data)
        root->left = insertInBST(root->left, d);
    else
        root->right = insertInBST(root->right, d);
    return root;
}

void takeInput(node *&root)
{
    while(true){
        int d;
        cout<<"Enter data-> ";
        cin>>d;
        if(d==-1)
            return;
        root = insertInBST(root, d);
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

int main()
{
    node * root = NULL;
    takeInput(root);
    cout<<endl<<"Level order print of the tree->"<<endl;
    levelOrderPrint(root);

    if(isBST(root))
        cout<<"The given tree is a BST\n";
    else
        cout<<"The given tree is not a BST\n";

    myPair s = isBalanced(root);
    if(s.balance)
        cout<<"The given tree is a balanced BST \n";
    else
        cout<<"The given tree is not a balanced BST\n";

    return 0;
}
