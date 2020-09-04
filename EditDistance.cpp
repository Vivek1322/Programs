
#include<bits/stdc++.h>
using namespace std;

int convertRec(string a, string b, int m, int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;

    if(a[m-1]==b[n-1])
        return convertRec(a, b, m-1, n-1);
    else
        return 1+min(min(convertRec(a, b, m-1, n), convertRec(a, b, m, n-1)), convertRec(a, b, m-1, n-1));
}

int convertTopDown(string a, string b, int i, int j, int **dp)
{
    if(i==0)
    {
        dp[i][j] = j;
        return j;
    }
    if(j==0)
    {
        dp[i][j] = i;
        return i;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
    {
        if(a[i-1]==b[j-1])
            dp[i][j] = convertTopDown(a, b, i-1, j-1, dp);
        else
            dp[i][j] = 1 + min(convertTopDown(a, b, i-1, j-1, dp), min(convertTopDown(a, b, i-1, j, dp), convertTopDown(a, b, i, j-1, dp)));
    }
    return dp[i][j];
}

int convertBottomUp(string a, string b, int m, int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            //first string is empty, only way is to insert all elements
            if(i==0)
                dp[i][j] = j;
            //second string is empty, only way is to append all elements
            else if(j==0)
                dp[i][j] = i;
            //characters match, move onto the next ones
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            //characters don't match, now we can either append, insert or substitute them
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[m][n];
}

int convert(string a, string b)
{
    int m = a.length();
    int n = b.length();
    int **dp = new int * [m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i] = new int [n+1];
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;
    }
    //return convertRec(a, b, m, n);
    return convertTopDown(a, b, m, n, dp);
    //return convertBottomUp(a, b, m, n);
}

int main()
{
    string a, b;
    cin>>a>>b;
    cout<<convert(a, b)<<endl;
    return 0;
}
