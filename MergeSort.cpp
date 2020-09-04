#include<bits/stdc++.h>
using namespace std;

void merges(int * left, int l, int * right, int r, int * a)
{
    int i=0, j=0, k=0;
    while(j<l && k<r)
    {
        if(left[j]<right[k])
        {
            a[i] = left[j];
            j++;
        }
        else
        {
            a[i] = right[k];
            k++;
        }
        i++;
    }
    while(j<l)
    {
        a[i] = left[j];
        i++;
        j++;
    }
    while(k<r)
    {
        a[i] = right[k];
        k++;
        i++;
    }
}

void mergeSort(int * a, int s, int e)
{
    if(s>=e)
        return;

    int mid = (s+e)/2;

    int * left = new int [mid+1];
    int * right = new int [e-mid];
    int i;
    for(i=0; i<mid+1; i++)
    {
        left[i] = a[i];
    }
    for(int j=0; j<e-mid; j++)
    {
        right[j] = a[i];
        i++;
    }

    mergeSort(left, 0, mid);
    mergeSort(right, 0, e-mid-1);

    merges(left, mid+1, right, e-mid, a);
}

int main()
{
    int n;
    cout<<"Enter the size of the array->";
    cin>>n;
    cout<<"Enter the elements of the array->";
    int * a = new int [n];
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }

    mergeSort(a, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
