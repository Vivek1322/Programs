#include<bits/stdc++.h>
using namespace std;

bool isValid(int count[], int k)
{
    int u = 0;
    for(int i=0; i<26; i++)
    {
        if(count[i]>0)
            u++;
    }
    return (u<=k);
}

void findCount(string s, int k)
{
    if(k==0)
        return;
    int maxSize = 1, maxSizeStart = 0;
    int curr_start = 0;
    int curr_end = 0;

    int n = s.length();
    int u = 0;
    int count[26];
    memset(count, 0, sizeof(count));
    for(int i=0; i<n; i++)
    {
        if(count[s[i]-'a']==0)
            u++;
        count[s[i]-'a']++;
    }
    if(u<k)
    {
        cout<<"Not enough unique characters.\n";
        return;
    }
    memset(count, 0, sizeof(count));
    count[s[0]-'a']++;

    for(int i=1; i<n; i++)
    {
        count[s[i]-'a']++;
        curr_end++;

        while(!isValid(count, k))
        {
            count[s[curr_start]-'a']--;
            curr_start++;
        }
        if(curr_end-curr_start+1>maxSize)
        {
            maxSize = curr_end-curr_start+1;
            maxSizeStart = curr_start;
        }
    }
    cout<<"Longest substring with "<<k<<" unique characters is "<<s.substr(maxSizeStart, maxSize)<<" with length "<<maxSize<<endl;
}

int main()
{
    string s;
    cout<<"Enter the string->";
    cin>>s;
    int k;
    cout<<"Enter the count for distinct characters->";
    cin>>k;

    findCount(s, k);

    return 0;
}

