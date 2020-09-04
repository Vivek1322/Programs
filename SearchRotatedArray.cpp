#include<bits/stdc++.h>
using namespace std;

int binarySearch(int * a, int s, int e, int key)
{
    int mid = (s+e)/2;
    if(s<=e)
    {
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return binarySearch(a, s, mid-1, key);
        else
            return binarySearch(a, mid+1, e, key);
    }
    else
        return -1;
}

int findPivot(int * a, int s, int e)
{
    int mid = (s+e)/2;
    if(s<=e)
    {
        if(mid>s && a[mid]<a[mid-1])
            return mid-1;
        else if(mid<e && a[mid]>a[mid+1])
            return mid;
        else if(a[s]>a[mid])
            return findPivot(a, s, mid-1);
        else
            return findPivot(a, mid+1, e);
    }
    else
        return -1;
}

int searchArray(int * a, int n, int key)
{
    int pivot = findPivot(a, 0, n-1);
    if(pivot!=-1)
    {
        if(key>=a[0])
            return binarySearch(a, 0, pivot, key);
        else
            return binarySearch(a, pivot+1, n-1, key);
    }
    else
        return -1;
}

int main()
{
    int n;
    cout<<"Enter the size of the array -> ";
    cin>>n;
    int * a = new int [n];
    cout<<"Enter the elements of the array -> ";
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<"Enter the key to be searched -> ";
    int key;
    cin>>key;

    cout<<"Search key is present at index "<<searchArray(a, n, key)<<endl;

    return 0;
}

