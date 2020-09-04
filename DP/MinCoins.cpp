#include<bits/stdc++.h>
using namespace std;

int coinsNeeded(int amount, int coins[], int n)
{
    if(amount==0)
        return 0;
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(amount-coins[i]>=0)
        {
            int smallAns = coinsNeeded(amount-coins[i], coins, n);
            if(smallAns!=INT_MAX)
                ans = min(ans, smallAns+1);
        }
    }
    return ans;
}

int coinsNeededBottomUp(int amount, int coins[], int n)
{
    int * dp = new int [amount+1];
    dp[0]=0;
    for(int rupee=1; rupee<=amount; rupee++)
    {
        dp[rupee]=INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(rupee-coins[i]>=0)
            {
                int smallAns = dp[rupee-coins[i]];
                if(smallAns!=INT_MAX)
                    dp[rupee]=min(smallAns+1, dp[rupee]);
            }
        }
    }
    return dp[amount];
}

int coinsNeededTopDown(int amount, int * dp, int coins[], int n)
{
    if(amount==0)
    {
        dp[amount]=0;
        return dp[amount];
    }
    if(dp[amount]!=-1)
        return dp[amount];
    else
    {
        dp[amount] = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(amount-coins[i]>=0)
            {
                int smallAns = coinsNeededTopDown(amount-coins[i], dp, coins, n);
                if(smallAns!=INT_MAX)
                    dp[amount] = min(smallAns+1, dp[amount]);
            }
        }
        return dp[amount];
    }
}

int main()
{
    int coins[] = {1,7,10};
    cout<<"Enter the amount->";
    int amount;
    cin>>amount;
    int * dp = new int [amount+1];
    for(int i=0; i<=amount;i++)
        dp[i]=-1;
    cout<<coinsNeededTopDown(amount, dp, coins, 3)<<endl;
    cout<<coinsNeededBottomUp(amount, coins, 3)<<endl;
    cout<<coinsNeeded(amount, coins, 3)<<endl;
    return 0;
}
