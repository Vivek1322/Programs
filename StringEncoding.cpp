#include<bits/stdc++.h>
using namespace std;

string encode(string s)
{
    string ans = "";
    int n = s.length();

    if(n==0)
        return ans;
    char c = s[0];
    int count = 1;
    int r = 0;

    for(int i=1; i<n; i++)
    {
        if(s[i]==c)
        {
            if(count==9)
            {
                r++;
                count = 0;
            }
            else
                count++;
        }
        else
        {
            if(r!=0)
                ans = ans + char(48+r) + char(48+count) + c;
            else
                ans = ans + char(48+count) + c;
            c = s[i];
            count = 1;
        }
    }
    if(r!=0)
        ans = ans + char(48+r) + char(48+count) + c;
    else
        ans = ans + char(48+count) + c;
    return ans;
}

int main()
{
    string s;
    cin>>s;

    cout<<encode(s)<<endl;

    return 0;
}

