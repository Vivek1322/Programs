#include<bits/stdc++.h>
using namespace std;

int partition(int * a, int s, int e)
{
    int pivot = e;
    int i = 0;

    for(int j=0; j<=e; j++)
    {
        if(a[j]<a[pivot])
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[pivot], a[i]);
    return i;
}

void quickSort(int * a, int s, int e)
{
    if(s>=e)
        return;

    int pivot = partition(a, s, e);

    quickSort(a, s, pivot-1);
    quickSort(a, pivot+1, e);
}

int main()
{
    int n;
    cout<<"Enter the size of the array->";
    cin>>n;
    int * a = new int [n];
    cout<<"Enter the elements of the array->";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }

    quickSort(a, 0, n-1);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
