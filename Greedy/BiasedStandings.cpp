#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> p, pair<int, int> q)
{
    return p.second<q.second;
}

void biasedStandings(vector<pair<int, int> > &v)
{
    sort(v.begin(), v.end(), myCmp);

    int badness = 0;
    for(int i=0; i<v.size(); i++)
    {
        cout<<"Rank "<<i+1<<" -> Team "<<v[i].first<<" [Expected Rank -> "<<v[i].second<<" ]"<<endl;
        badness += abs(i+1-v[i].second);
    }
    cout<<"Badness value = "<<badness<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number of teams -> ";
    cin>>n;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++)
    {
        int a;
        cout<<"Enter the expected rank of team "<<i+1<<" -> ";
        cin>>a;
        v.push_back(make_pair(i+1, a));
    }
    biasedStandings(v);
    return 0;
}
