#include<bits/stdc++.h>
using namespace std;


int palindromeUtil(string s, int i, int j, int ans, int current_ans)
{
    if(i>j)
    {
        ans = max(ans, current_ans);
        return ans;
    }
    if(i==j)
    {
        current_ans++;
        ans = max(ans, current_ans);
        return ans;
    }
    if(s[i]==s[j])
    {
        current_ans += 2;
        return palindromeUtil(s, i+1, j-1, ans, current_ans);
    }
    else
    {
        ans = max(ans, current_ans);
        current_ans = 0;
        return max(max(palindromeUtil(s, i+1, j, ans, current_ans), palindromeUtil(s, i, j-1, ans, current_ans)), ans);
    }
}

int palindrome(string s)
{
    int n = s.length();
    if(n==0 || n==1)
        return n;
    else
        return palindromeUtil(s, 0, n-1, 0, 0);
}

int main()
{
    string s;
    cin>>s;
    cout<<palindrome(s)<<endl;
    return 0;
}
