#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<double, double> p, pair<double, double> q)
{
    return p.second>q.second;
}

int knapsack(vector<pair<double, double> > &v, int w, int n)
{
    if(w==0 || n==0)
        return 0;

    int ans = 0;
    for(int i=0; i<n; i++)
        v[i].second = v[i].second/v[i].first;
    sort(v.begin(), v.end(), myCmp);

    for(int i=0; i<n; i++)
    {
        if(w==0)
            break;
        if(w-v[i].first >= 0)
        {
            ans = ans + (v[i].second * v[i].first);
            w = w - v[i].first;
        }
        else
        {
            ans = ans + (w*v[i].second);
            w = 0;
        }
    }
    return ans;
}

int main()
{
    double wts[5] = {2,5,3,1,2};
    double prices[5] = {10,20,9,5,8};

    vector<pair<double, double> > v;
    for(int i=0; i<5; i++)
        v.push_back(make_pair(wts[i], prices[i]));

    int w;
    cout<<"Enter the weight of the bag -> ";
    cin>>w;

    cout<<"Maximum profit -> "<<knapsack(v, w, 5)<<endl;

    return 0;
}
