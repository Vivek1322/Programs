#include<bits/stdc++.h>
using namespace std;

void productArray(int * a, int n)
{
    int p = 1;
    for(int i=0; i<n; i++)
        p *= a[i];
    for(int i=0; i<n; i++)
        a[i] = p/a[i];
}

void productArrayWithoutDivision(int * a, int n)
{
    int * left = new int [n];
    int * right = new int [n];
    left[0] = 1;
    right[n-1] = 1;

    for(int i=1; i<n; i++)
        left[i] = left[i-1]*a[i-1];
    for(int i=n-2; i>=0; i--)
        right[i] = right[i+1]*a[i+1];
    for(int i=0; i<n; i++)
        a[i] = left[i]*right[i];
}

int main()
{
    int n, sum;
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

    productArrayWithoutDivision(a, n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}

