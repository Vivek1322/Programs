#include<bits/stdc++.h>
using namespace std;

void spiralPrint(int ** a, int m, int n)
{
    int top = 0, left = 0;
    int bottom = m-1;
    int right = n-1;

    while(1)
    {
        if(left>right)
            break;
        for(int i=left; i<=right; i++)
            cout<<a[top][i]<<endl;
        top++;

        if(top>bottom)
            break;
        for(int i=top; i<=bottom; i++)
            cout<<a[i][right]<<endl;
        right--;

        if(left>right)
            break;
        for(int i=right; i>=left; i--)
            cout<<a[bottom][i]<<endl;
        bottom--;

        if(top>bottom)
            break;
        for(int i=bottom; i>=top; i--)
            cout<<a[i][left]<<endl;
        left++;
    }
}

int main()
{
    int m, n;
    cout<<"Enter the number of rows in the array -> ";
    cin>>m;
    cout<<"Enter the number of columns in the array -> ";
    cin>>n;

    int ** a = new int * [m];
    cout<<"Enter the elements of the array -> ";
    for(int i=0; i<m; i++)
    {
        a[i] = new int [n];
        for(int j=0; j<n; j++)
            cin>>a[i][j];
    }

    spiralPrint(a, m, n);

    return 0;
}

