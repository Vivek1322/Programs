#include<bits/stdc++.h>
using namespace std;

int ways(int i, int j)
{
    if(i==0 || j==0)
        return 1;
    else
        return ways(i-1, j)+ways(i, j-1);
}

int waysTopDown(int i, int j, int **dp)
{
    if(i==0 || j==0)
    {
        dp[i][j]=1;
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        dp[i][j] = waysTopDown(i-1, j, dp) + waysTopDown(i, j-1, dp);
        return dp[i][j];
    }
}

int waysBottomUp(int m, int n)
{
    int dp[m+1][n+1]={-1};
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
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
