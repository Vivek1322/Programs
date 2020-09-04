#include<bits/stdc++.h>
using namespace std;

int minCostPath(int cost[8][8], int i, int j)
{
    if(i==0 && j==0)
        return cost[i][j];
    else if(i!=0 && j==0)
        return cost[i][j] + minCostPath(cost, i-1, j);
    else if(i==0 && j!=0)
        return cost[i][j] + minCostPath(cost, i, j-1);
    else
        return cost[i][j] + min(minCostPath(cost, i-1, j), minCostPath(cost, i, j-1));
}

int minCostPathTopDown(int cost[8][8], int i, int j, int **dp)
{
    if(i==0 && j==0)
    {
        dp[i][j]=cost[i][j];
        return dp[i][j];
    }
    else if(dp[i][j]!=-1)
        return dp[i][j];
    else if(i!=0 && j==0)
    {
        dp[i][j] = cost[i][j] + minCostPath(cost, i-1, j);
        return dp[i][j];
    }
    else if(i==0 && j!=0)
    {
        dp[i][j] = cost[i][j] + minCostPath(cost, i, j-1);
        return dp[i][j];
    }
    else
    {
        dp[i][j] = cost[i][j] + min(minCostPath(cost, i-1, j), minCostPath(cost, i, j-1));
        return dp[i][j];
    }
}

int minCostPathBottomUp(int cost[8][8], int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = cost[i][j];
            else if(i!=0 && j==0)
                dp[i][j] = cost[i][j] + dp[i-1][j];
            else if(i==0 && j!=0)
                dp[i][j] = cost[i][j] + dp[i][j-1];
            else
                dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
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
    int cost[8][8] = {{2, 8, 5, 1, 10, 5, 9, 9},
                       {3, 5, 6, 6, 2, 8, 2, 2},
                       {6, 3, 8, 7, 2, 5, 3, 4},
                       {3, 3, 2, 7, 9, 6, 8, 7},
                       {2, 9, 10, 3, 8, 10, 6, 5},
                       {4, 2, 3, 4, 4, 5, 2, 2},
                       {4, 9, 8, 5, 3, 8, 8, 10},
                       {4, 2, 10, 9, 7, 6, 1, 3} };
    int **dp = new int* [i+1];
    for(int m = 0; m<=i; m++)
    {
        dp[m] = new int [j+1];
        for(int n=0; n<=j; n++)
        {
            dp[m][n] = -1;
        }
    }
    cout<<"Cost->"<<minCostPathTopDown(cost, i, j, dp)<<endl;
    cout<<"Cost->"<<minCostPathBottomUp(cost, i, j)<<endl;
    cout<<"Cost->"<<minCostPath(cost, i, j)<<endl;
    return 0;
}
