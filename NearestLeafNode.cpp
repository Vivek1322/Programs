#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		int val;
		node * left;
		node * right;

		node(int val){
			this->val = val;
			this->left = NULL;
			this->right = NULL;
		}
};

node * find(node * root, int key){
	if(root==NULL)
		return NULL;
	if(root->val == key)
		return root;
	node * left = find(root->left, key);
	node * right = find(root->right, key);
	return (left!=NULL ? left : right);
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
        cout<<"Enter the children of "<<f->val<<endl;
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
            cout<<f->val<<" ";
        }
    }
}

void solve(node * root, int l, int &ans){
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL){
		ans = min(ans, l);
	}
	else{
		solve(root->left, l+1, ans);
		solve(root->right, l+1, ans);
	}
	return;
}

int main() {
	// your code goes here
	node * root = NULL;
	levelOrderInput(root);
	cout<<endl;
	levelOrderPrint(root);
	int key;
	cin>>key;
	node * foundRoot = find(root, key);
	int ans = INT_MAX;
	solve(foundRoot, 0, ans);
	cout<<ans<<endl;
	return 0;
}
