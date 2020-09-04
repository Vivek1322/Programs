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

void inorder(node * root, vector<int> &v)
{
    if(root==NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

pair<int, int> findPairUtil(vector<int> &v, int k)
{
    int n = v.size();
    int i=0, j=n-1;
    while(i<j)
    {
        if(v[i]+v[j]==k)
            return make_pair(v[i],v[j]);
        if(v[i]+v[j]<k)
            i++;
        else
            j--;
    }
    return make_pair(INT_MIN, INT_MIN);
}

pair<int, int> findPair(node * root, int k)
{
    vector<int> v;
    inorder(root, v);
    pair<int, int> p = findPairUtil(v, k);
    return p;
}

bool pairFindUtil(node * root, set<int> &s, int k)
{
    if(root==NULL)
        return false;
    if(pairFindUtil(root->left, s, k))
        return true;
    if(s.find(k-root->data)!=s.end())
    {
        cout<<"Following nodes add up to the required sum->"<<root->data<<" and "<<k-root->data<<endl;
        return true;
    }
    else
        s.insert(root->data);
    return pairFindUtil(root->right, s, k);
}

void pairFind(node * root, int k)
{
    set<int> s;
    if(!pairFindUtil(root, s, k))
        cout<<"No such pair exists in the given BST.\n";
}

int main()
{
    node * root = NULL;
    root = insertInBST(root, 10);
    root = insertInBST(root, 5);
    root = insertInBST(root, 15);
    root = insertInBST(root, 11);
    root = insertInBST(root, 16);

    levelOrderPrint(root);

    int k = 20;
    pair<int, int> p = findPair(root, k);
    if(p.first!=INT_MIN)
        cout<<"Following nodes add up to the required sum->"<<p.first<<" and "<<p.second<<endl;
    else
        cout<<"No such pair exists in the given BST."<<endl;

    pairFind(root, k);

    return 0;
}
