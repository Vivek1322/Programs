#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> p, pair<int, int> q)
{
    return p.second<q.second;
}

int selection(vector<pair<int, int> > &v)
{
    sort(v.begin(), v.end(), myCmp);

    int finish = v[0].second;
    int count = 1;

    for(int i=1; i<v.size(); i++)
    {
        if(v[i].first >= finish)
        {
            finish = v[i].second;
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter the number of activities->";
    cin>>n;
    vector<pair<int, int> > v;
    cout<<"All the timings must be in 24 hour format.\n";
    for(int i=0; i<n; i++)
    {
        int a, b;
        cout<<"Enter the starting time of activity "<<i+1<<"->";
        cin>>a;
        cout<<"Enter the finishing time of activity "<<i+1<<"->";
        cin>>b;
        v.push_back(make_pair(a, b));
    }

    cout<<"Maximum number of activities that can be performed are -> "<<selection(v)<<endl;
    return 0;
}
