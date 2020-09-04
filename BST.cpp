
/// node * root would not initialize root to NULL but some random value

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

node * searchBST(node * root, int key)
{
    if(root==NULL)
        return NULL;
    if(key==root->data)
        return root;
    else if(key<root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

node * minReplacement(node * root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
    {
        root= root->left;
    }
    return root;
}

node * deleteFromBST(node * root, int key)
{
    if(root==NULL)
        return root;
    if(root->data==key)
    {
        /// NO CHILD
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        /// 1 CHILD
        else if(root->left!=NULL && root->right==NULL)
        {
            node * temp = root;
            root = temp->left;
            delete temp;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            node * temp = root;
            root = temp->right;
            delete temp;
        }
        node * replacement = minReplacement(root);
        root->data = replacement->data;
        root->right = deleteFromBST(root->right, replacement->data);
    }
    else if(key<root->data)
        root->left = deleteFromBST(root->left, key);
    else
        root->right = deleteFromBST(root->right, key);
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
    node * root = NULL;     /// Make it NULL explicitly
    takeInput(root);
    cout<<endl<<"Level order print of the tree->"<<endl;
    levelOrderPrint(root);

    int key;
    cout<<"Enter key to search->";
    cin>>key;
    if(searchBST(root, key))
        cout<<"Key present at location "<<searchBST(root, key)<<endl;
    else
        cout<<"Key is not present"<<endl;
    int n;
    cout<<"Enter key to be deleted->";
    cin>>n;
    root = deleteFromBST(root, n);
    cout<<endl<<"Level order print after deletion->"<<endl;
    levelOrderPrint(root);

    return 0;
}
