/*
1. Merge sort O(n log n)
2. Other method with O(n) time uses binary indexed trees and red-black trees
*/

#include<bits/stdc++.h>
using namespace std;

int myMerge(int * a, int * temp, int left, int mid, int right)
{
    int inv = 0;
    int k = left;
    int i = left;
    int j = mid;
    while(i<mid && j<=right)
    {
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];

            ///both left and right array are sorted so if a[i]<a[j], then all the elements of the left array after i would be greater than jth elementof the right array
            inv += mid-i;
        }
    }
    while(i<mid)
        temp[k++] = a[i++];
    while(j<=right)
        temp[k++] = a[j++];

    for(i=left; i<=right; i++)
        a[i] = temp[i];
    return inv;
}

int mergeSort(int * a, int * temp, int i, int j)
{
    int inv = 0;
    int mid;
    if(i<j)
    {
        mid = (i+j)/2;
        int inv_left = mergeSort(a, temp, i, mid);
        int inv_right = mergeSort(a, temp, mid+1, j);
        inv = inv_left + inv_right + myMerge(a, temp, i, mid+1, j);
    }
    return inv;
}

int inversions(int * a, int n)
{
    int * temp = new int[n];

    return mergeSort(a, temp, 0, n-1);
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

    cout<<"No of inversions in the given array is "<<inversions(a, n)<<endl;

    return 0;
}
