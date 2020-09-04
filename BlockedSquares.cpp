#include<bits/stdc++.h>
using namespace std;

int ways(int blocked[8][8], int i, int j)
{
    if(blocked[i][j]==1)
        return 0;
    else if(i==0 || j==0)
        return 1;
    else
        return ways(blocked, i-1, j)+ways(blocked, i, j-1);
}

int waysTopDown(int blocked[8][8], int i, int j, int **dp)
{
    if(blocked[i][j]==1)
    {
        dp[i][j]=0;
        return dp[i][j];
    }
    else if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        if(i==0 || j==0)
        {
            dp[i][j]=1;
            return dp[i][j];
        }
        else
        {
            dp[i][j] = waysTopDown(blocked, i-1, j, dp)+waysTopDown(blocked, i, j-1, dp);
            return dp[i][j];
        }
    }
}

int waysBottomUp(int blocked[8][8], int m, int n)
{
    int dp[m+1][n+1]={0};

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(blocked[i][j]==1)
                dp[i][j]=0;
            else if(i==0 || j==0)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
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
    int blocked[8][8] = {{0,1,0,0,0,1,0,0},
                       {0,0,0,1,0,0,1,1},
                       {1,0,0,0,1,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {1,1,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0},
                       {0,0,1,0,0,0,0,0},
                       {1,0,1,0,0,1,0,0} };
    int **dp = new int* [i+1];
    for(int m = 0; m<=i; m++)
    {
        dp[m] = new int [j+1];
        for(int n=0; n<=j; n++)
        {
            dp[m][n] = -1;
        }
    }
    cout<<"Ways->"<<waysTopDown(blocked, i, j, dp)<<endl;
    cout<<"Ways->"<<waysBottomUp(blocked, i, j)<<endl;
    cout<<"Ways->"<<ways(blocked, i, j)<<endl;
    return 0;
}
