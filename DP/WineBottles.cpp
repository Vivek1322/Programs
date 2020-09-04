#include<bits/stdc++.h>
using namespace std;

int maxPrice(int *wines, int i, int j, int day)
{
    if(i>j)
        return 0;
    int a = day*wines[i] + maxPrice(wines, i+1, j, day+1);
    int b = day*wines[j] + maxPrice(wines, i, j-1, day+1);
    return max(a, b);
}

int maxPriceTopDown(int wines[], int i, int j, int day, int **dp)
{
    if(i>j)
    {
        dp[i][j]=0;
        return dp[i][j];
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    int a = day*wines[i] + maxPriceTopDown(wines, i+1, j, day+1, dp);
    int b = day*wines[j] + maxPriceTopDown(wines, i, j-1, day+1, dp);
    dp[i][j] = max(a, b);
    return dp[i][j];
}

int maxPriceBottomUp(int wines[], int a, int b)
{
    int dp[b+1][b+1];
    int day = 0;
    for(int i=b; i>=0; i--)
    {
        for(int j=0; j<=b; j++)
        {
            day = (b-j)+(i-a)+1;
            if(i==j)
                dp[i][j]=day*wines[i];
            else if(i>j)
                dp[i][j]=0;
            else
            {
                int x = day*wines[i] + dp[i+1][j];
                int y = day*wines[j] + dp[i][j-1];
                dp[i][j] = max(x, y);
            }
        }
    }
    return dp[a][b];
}

int main()
{
    int wines[] ={2,6,3,1,4,7};
    int n = sizeof(wines)/sizeof(wines[0]);

    ///if we take size of array as n*n it would give segmentation fault for the case i=3, j=2, day=4
    int **dp = new int * [n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]=new int [n+1];
        for(int j = 0; j<=n; j++)
            dp[i][j] = -1;
    }

    cout<<maxPriceTopDown(wines, 0, n-1, 1, dp)<<endl;
    cout<<maxPriceBottomUp(wines, 0, n-1)<<endl;
    cout<<maxPrice(wines, 0, n-1, 1)<<endl;
    return 0;
}
