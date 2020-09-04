#include<bits/stdc++.h>
using namespace std;

int ways(int m, int n)
{
    if(m==0 && n==0)
        return 1;

    int a=0;
    int b=0;

    for(int i=1; i<=m; i++)
        a = a+ways(m-i, n);
    for(int i=1; i<=n; i++)
        b = b+ways(m, n-i);

    return a+b;
}

int waysTopDown(int m, int n, int **dp)
{
    if(m==0 && n==0)
    {
        dp[m][n] = 1;
        return dp[m][n];
    }
    if(dp[m][n]!=-1)
        return dp[m][n];
    else
    {
        int a=0, b=0;
        for(int i=1; i<=m; i++)
            a = a+waysTopDown(m-i, n, dp);
        for(int j=1; j<=n; j++)
            b = b+waysTopDown(m, n-j, dp);
        dp[m][n] = a+b;
    }
    return dp[m][n];
}

int waysBottomUp(int m, int n)
{
    int dp[m+1][n+1]={0};

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = 1;
                continue;
            }
            int a=0, b=0;
            for(int k=1; k<=i; k++)
                a = a + dp[i-k][j];
            for(int k=1; k<=j; k++)
                b = b + dp[i][j-k];
            dp[i][j] = a+b;
        }
    }
    return dp[m][n];
}

int main()
{
    cout<<"Enter the destination(index beginning from zero)->\n";
    cout<<"i=";
    int i,j;
    cin>>i;
    cout<<"j=";
    cin>>j;
    int **dp = new int* [i+1];
    for(int m = 0; m<=i; m++)
    {
        dp[m] = new int [j+1];
        for(int n=0; n<=j; n++)
        {
            dp[m][n] = -1;
        }
    }
    cout<<"Ways->"<<waysTopDown(i, j, dp)<<endl;
    cout<<"Ways->"<<waysBottomUp(i, j)<<endl;
    cout<<"Ways->"<<ways(i, j)<<endl;
    return 0;
}
