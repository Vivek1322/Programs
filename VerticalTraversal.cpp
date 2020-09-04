
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

void vop(node * root, map<int, vector<int> > &m, int d=0)
{
    if(root==NULL)
        return;
    m[d].push_back(root->data);
    vop(root->left, m, d-1);
    vop(root->right, m, d+1);
}

int main()
{
    node * root;
    levelOrderInput(root);

    map<int, vector<int> > m;
    vop(root, m);

    map<int, vector<int> > :: iterator it;
    for( it = m.begin(); it != m.end(); it++)
    {
        cout<<it->first<<"->";
        for(int j=0; j<(it->second).size(); j++)
        {
            cout<<it->second[j]<<",";
        }
        cout<<endl;
    }

    return 0;
}
