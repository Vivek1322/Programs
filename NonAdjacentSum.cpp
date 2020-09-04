#include<bits/stdc++.h>
using namespace std;

int maxSum(int * a, int n)
{
    if(n==0)
        return 0;
    int inc = a[0];
    int exc = 0;
    int exc_new = 0;

    for(int i=1; i<n; i++)
    {
        exc_new = max(inc, exc);
        inc = exc + a[i];
        exc = exc_new;
    }
    return max(inc, exc);
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
    cout<<maxSum(a, n)<<endl;
    return 0;
}

