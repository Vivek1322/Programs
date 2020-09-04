///Sorting would take O(N log N) time and O(1) space
///Hashing would take O(N) time but O(N) space

#include<bits/stdc++.h>
using namespace std;

int segregate(int * a,  int n)
{
    int i=0, j=0;
    while(j<n)
    {
        if(a[j]<=0)
            swap(a[i++], a[j]);
        j++;
    }
    return i;
}

int smallestUtil(int * a, int n)
{
    for(int i=0; i<n; i++)
    {
        if(abs(a[i])-1 < n && a[abs(a[i])-1]>0)
            a[abs(a[i])-1] = -a[abs(a[i])-1];
    }

    for(int i=0; i<n; i++)
    {
        if(a[i]>0)
            return i+1;
    }
    return n+1;
}

int smallest(int * a, int n)
{
    int shift = segregate(a, n);

    return smallestUtil(a+shift, n-shift);
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
    int ans = smallest(a, n);
    cout<<"Smallest missing positive integer in the given array is "<<ans<<endl;
    return 0;
}

