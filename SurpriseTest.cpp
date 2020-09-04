#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    int n;
    cout<<"Enter the maximum difficulty level->";
    cin>>n;

    for(int i=1; i<=31; i++)
    {
        int x;
        cout<<"Enter the difficulty level of today's question->";
        cin>>x;
        m[x]++;

        if(m.size()==n)
        {
            cout<<"You can take a test today.\n";
            map<int, int> ::iterator it;
            for(it=m.begin(); it!=m.end();)
            {
                cout<<it->first<<" "<<it->second<<endl;
                m[it->first]--;
                cout<<it->first<<" "<<it->second<<endl;
                if(m[it->first]==0)
                {
                    map<int, int> :: iterator i;
                    i = it;
                    it++;
                    m.erase(i);
                }
                else
                {
                    it++;
                }
            }
        }
        else
            cout<<"You cannot take a test today.\n";
    }

    return 0;
}


