#include<bits/stdc++.h>
using namespace std;

int coinWays(int amt, int coins[], int n)
{
    if(amt==0 || n==0)
        return 1;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(amt-coins[i]>=0)
        {
            ans += coinWays(amt-coins[i], coins, n);
        }
    }
    return ans;
}

int coinWaysBottomUp(int amt, int coins[], int n)
{
    int dp[amt+1]={0};
    dp[0] = 1;
    for(int i=1; i<=amt; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-coins[j]>=0)
                dp[i] += dp[i-coins[j]];
        }
    }
    return dp[amt];
}

int coinWaysTopDown(int amt, int coins[], int n, int *dp)
{
    if(amt==0)
    {
        dp[amt]=1;
        return dp[amt];
    }
    if(dp[amt]!=0)
        return dp[amt];
    else
    {
        for(int i=0; i<n; i++)
        {
            if(amt-coins[i]>=0)
                dp[amt] += coinWaysTopDown(amt-coins[i], coins, n, dp);
        }
    }
    return dp[amt];
}

int main()
{
    int coins[3] = {1,7,10};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount;
    cout<<"Enter the amount->";
    cin>>amount;
    int * dp = new int [amount+1];
    for(int i=0; i<=amount; i++)
    {
        dp[i] = 0;
    }
    cout<<coinWaysTopDown(amount, coins, n, dp)<<endl;
    cout<<coinWaysBottomUp(amount, coins, n)<<endl;
    cout<<coinWays(amount, coins, n)<<endl;
    return 0;
}
