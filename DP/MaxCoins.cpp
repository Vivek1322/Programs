
#include<bits/stdc++.h>
using namespace std;

int maxCoins(int coins[3][4], int i, int j)
{
    if(i==0 && j==0)
        return coins[i][j];
    else if(i==0 && j!=0)
        return coins[i][j]+maxCoins(coins, i, j-1);
    else if (i!=0 && j==0)
        return coins[i][j]+maxCoins(coins, i-1, j);
    return coins[i][j]+max(maxCoins(coins, i-1, j), maxCoins(coins, i, j-1));
}

int maxCoinsBOttomUp(int coins[3][4], int a, int b)
{
    int dp[3][4];
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = coins[i][j];
            else if(i==0 && j!=0)
                dp[i][j] = coins[i][j] + dp[i][j-1];
            else if(i!=0 && j==0)
                dp[i][j] = coins[i][j] + dp[i-1][j];
            else
                dp[i][j] = coins[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][b];
}

int maxCoinsTopDown(int coins[3][4], int i, int j, int **dp)
{
    if(i==0 && j==0)
    {
        dp[i][j] = coins[i][j];
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        if(i!=0 && j==0)
        {
            dp[i][j] = coins[i][j] + maxCoinsTopDown(coins, i-1, j, dp);
            return dp[i][j];
        }
        else if(i==0 && j!=0)
        {
            dp[i][j] = coins[i][j] + maxCoinsTopDown(coins, i, j-1, dp);
            return dp[i][j];
        }
        else
        {
            dp[i][j] = coins[i][j] + max(maxCoinsTopDown(coins, i-1, j, dp), maxCoinsTopDown(coins, i, j-1, dp));
            return dp[i][j];
        }
    }
}

int main()
{
    int coins[3][4] = {{0,3,1,1},
                        {2,0,0,4},
                        {1,5,3,1}};
    int n=3, m=4;
    int ** dp = new int * [n];
    for(int i=0; i<n; i++)
    {
        dp[i] = new int [m];
        for(int j=0; j<m; j++)
            dp[i][j] = -1;
    }

    cout<<maxCoinsBOttomUp(coins, 2, 3)<<endl;
    cout<<maxCoinsTopDown(coins, 2, 3, dp)<<endl;

    cout<<maxCoins(coins, 2, 3)<<endl;
    return 0;
}
