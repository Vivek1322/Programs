#include<bits/stdc++.h>
using namespace std;

int chopstics(vector<int> &v, int d)
{
    sort(v.begin(), v.end());
    int count = 0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i+1]-v[i]<=d)
        {
            count++;
            i++;
        }
    }
    return count;
}

int main()
{
    int n, d;
    cout<<"Enter the number of chopsticks -> ";
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cout<<"Enter the length of chopstick "<<i+1<<" -> ";
        cin>>x;
        v.push_back(x);
    }
    cout<<"Maximum difference in lengths allowed to enable pairing -> ";
    cin>>d;
    cout<<endl<<"Maximum number of pairs that can be formed -> "<<chopstics(v, d)<<endl;

    return 0;
}
