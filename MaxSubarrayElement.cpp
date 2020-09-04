/*
1. Using segment tree
2. Using deque and storing the required indices only
*/


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
    tree[index] = max(tree[2*index], tree[2*index + 1]);
    return;
}

int query(int * tree, int index, int s, int e, int qs, int qe)
{
    //No overlap
    if(qs>e || qe<s)
        return INT_MIN;

    //Complete overlap
    if(s>=qs && e<=qe)
        return tree[index];

    //Partial overlap
    int mid = (s+e)/2;
    int left = query(tree, 2*index, s, mid, qs, qe);
    int right = query(tree, 2*index+1, mid+1, e, qs, qe);
    return max(left, right);
}

void findMax(int * a, int n, int k)
{
    int * tree = new int[4*n + 1];
    buildTree(tree, a, 1, 0, n-1);
    int j = 0;
    for(int i=k-1; i<n; i++)
    {
        cout<<"Max element in the range "<<j<<" and "<<i<<"->"<<query(tree, 1, 0, n-1, j, i)<<endl;
        j++;
    }
}

void findKMax(int * a, int n, int k)
{
    deque<int> q;
    int i=0;
    for(i=0; i<k; i++)
    {
        while((!q.empty()) && a[q.back()]<=a[i])
            q.pop_back();
        q.push_back(i);
    }
    for(i=k; i<n; i++)
    {
        cout<<a[q.front()]<<" ";

        while((!q.empty())  && q.front()<=i-k)
            q.pop_front();
        while((!q.empty()) && a[q.back()]<=a[i])
            q.pop_back();
        q.push_back(i);
    }
    cout<<a[q.front()]<<endl;
}

int main()
{
    int n;
    cout<<"Enter the length of the array->";
    cin>>n;
    int * a = new int [n];
    cout<<"Enter the elements of the array->";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }

    int k;
    cout<<"Enter the range->";
    cin>>k;

    findMax(a, n, k);

    findKMax(a, n, k);

    return 0;
}

