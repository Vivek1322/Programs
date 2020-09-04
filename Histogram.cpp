/*
1. Divide and conquer
2. Using stacks
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
        tree[index] = s;
        return;
    }

    //Recursive case
    int mid = (s+e)/2;
    buildTree(tree, a, 2*index, s, mid);
    buildTree(tree, a, 2*index + 1, mid+1, e);
    tree[index] = a[tree[2*index]]<a[tree[2*index+1]]?tree[2*index]:tree[2*index+1];
    return;
}

int query(int * tree, int * a, int index, int s, int e, int qs, int qe)
{
    //No overlap
    if(qs>e || qe<s)
        return -1;

    //Complete overlap
    if(s>=qs && e<=qe)
        return tree[index];

    //Partial overlap
    int mid = (s+e)/2;
    int left = query(tree, a, 2*index, s, mid, qs, qe);
    int right = query(tree, a, 2*index+1, mid+1, e, qs, qe);
    if(left==-1)
        return right;
    else if(right==-1)
        return left;
    else
        return a[left]<a[right]?left:right;
}

int maxAreaRec(int * tree, int * a, int n, int s, int e)
{
    if(s>e)
        return INT_MIN;
    else if(s==e)
        return a[s];

    int m = query(tree, a, 1, 0, n-1, s, e);
    int ans = max(max(maxAreaRec(tree, a, n, s, m-1), maxAreaRec(tree, a, n, m+1, e)), a[m]*(e-s+1));
    return ans;
}

int maxArea(int * a, int n)
{
    int * tree = new int [4*n + 1];
    buildTree(tree, a, 1, 0, n-1);

    return maxAreaRec(tree, a, n, 0, n-1);
}

int getMaxArea(int * a, int n)
{
    int area = 0;
    int max_area = -1;
    stack<int> s;
    s.push(0);
    int top, i;
    for(i=1; i<n; i++)
    {
        if(a[i]>a[s.top()])
            s.push(i);
        else
        {
            while(!s.empty() && a[i]<a[s.top()])
            {
                top = s.top();
                s.pop();
                if(s.empty())
                    area = a[top]*i;
                else
                    area = a[top]*(i-s.top()-1);
                if(max_area<area)
                    max_area = area;
            }
            s.push(i);
        }
    }
    while(!s.empty())
    {
            top = s.top();
            s.pop();
            if(s.empty())
                area = a[top]*i;
            else
                area = a[top]+(i-s.top()-1);
            if(max_area<area)
                max_area = area;
    }

    return max_area;
}

int main()
{
    cout<<"Enter the size of the array->";
    int n;
    cin>>n;
    int * a = new int[n];
    cout<<"Enter the elements of the array->";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }
    cout<<maxArea(a, n)<<endl;
    cout<<getMaxArea(a, n)<<endl;

    return 0;
}
