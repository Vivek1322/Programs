#include<bits/stdc++.h>
using namespace std;

void rotateArray(int * a, int n, int k)
{
    if(k==0 || k==n)
        return;
    int * temp = new int [k];
    for(int i=0; i<k; i++)
    {
        temp[i] = a[i];
    }
    int i=0, j=k;
    while(j<n)
    {
        a[i++] = a[j++];
    }
    for(int x=0; x<k; x++)
    {
        a[i++] = temp[x];
    }
}

void rotateArray2(int * a, int n, int k)
{
    if(k==0 || k==n)
        return;
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n-1; j++)
            swap(a[j], a[j+1]);
    }
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
    int k;
    cout<<"Rotation required->";
    cin>>k;

    //rotateArray(a, n, k);
    rotateArray2(a, n, k);

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
