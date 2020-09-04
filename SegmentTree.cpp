
///SEGMENT TREE FOR STORING MINIMUM VALUES IN A GIVEN RANGE OF INDICES OF AN ARRAY

#include<bits/stdc++.h>
using namespace std;

void buildTree(int * tree, int * a, int index, int s, int e)
{
    //Base case
    if(s>e)
        return;

    //Base case - Leaf node
    if(s==e)
    {
        tree[index] = a[s];
        return;
    }

    //Recursive case
    int mid = (s+e)/2;
    buildTree(tree, a, 2*index, s, mid);
    buildTree(tree, a, 2*index + 1, mid+1, e);
    tree[index] = min(tree[2*index], tree[2*index + 1]);
    return;
}

int query(int * tree, int index, int s, int e, int qs, int qe)
{
    //No overlap
    if(qs>e || qe<s)
        return INT_MAX;

    //Complete overlap
    if(s>=qs && e<=qe)
        return tree[index];

    //Partial overlap
    int mid = (s+e)/2;
    int left = query(tree, 2*index, s, mid, qs, qe);
    int right = query(tree, 2*index+1, mid+1, e, qs, qe);
    return min(left, right);
}

void updateNode(int * tree, int index, int s, int e, int i, int value)
{
    //No overlap
    if(i<s || i>e)
        return;

    //Complete overlap - Leaf node
    if(s==e)
    {
        tree[index] = value;
        return;
    }

    //Partial overlap
    int mid = (s+e)/2;
    updateNode(tree, 2*index, s, mid, i, value);
    updateNode(tree, 2*index+1, mid+1, e, i, value);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void updateRange(int * tree, int index, int s, int e, int rs, int re, int inc)
{
    //No overlap
    if(rs>e || re<s)
        return;

    //Complete overlap
    if(s==e)
    {
        tree[index] += inc;
        return;
    }

    //Partial overlap
    int mid = (s+e)/2;
    updateRange(tree, 2*index, s, mid, rs, re, inc);
    updateRange(tree, 2*index+1, mid+1, e, rs, re, inc);
    tree[index] = min(tree[2*index], tree[2*index+1]);
}

int main()
{
    int n;
    cout<<"Enter the size of the array->";
    cin>>n;
    cout<<"Enter the elements->";
    int * a = new int [n];
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }
    int * tree = new int [4*n +1];

    buildTree(tree, a, 1, 0, n-1);

    for(int i=0; i<4*n+1; i++)
        cout<<tree[i]<<" ";

    cout<<"\nNo of test queries->";
    int t;
    cin>>t;

    while(t--)
    {
        cout<<"Enter the range->";
        int qs, qe;
        cin>>qs>>qe;
        cout<<"Minimum element in the given range->"<<query(tree, 1, 0, n-1, qs, qe)<<endl;
    }

    int c;
    cout<<"Press 0 for node update and 1 for range update->";
    cin>>c;

    if(c==0)
    {
        int i, value;
        cout<<"Enter the position of the node->";
        cin>>i;
        cout<<"Enter the new value of the node->";
        cin>>value;
        updateNode(tree, 1, 0, n-1, i, value);
    }
    else
    {
        int rs, re, inc;
        cout<<"Enter the range for range update->";
        cin>>rs>>re;
        cout<<"Enter the increment for each node in above range->";
        cin>>inc;
        updateRange(tree, 1, 0, n-1, rs, re, inc);
    }

    int q;
    cout<<"No of test queries->";
    cin>>q;

    while(q--)
    {
        cout<<"Enter the range->";
        int qs, qe;
        cin>>qs>>qe;
        cout<<"Minimum element in the given range->"<<query(tree, 1, 0, n-1, qs, qe)<<endl;
    }

    for(int i=0; i<4*n+1; i++)
        cout<<tree[i]<<" ";

    return 0;
}
