#include<bits/stdc++.h>
using namespace std;

int threading(vector<int> &black, vector<int> &red)
{
    sort(black.begin(), black.end());
    sort(red.begin(), red.end());

    int length = 0;

    for(int i=0; i<red.size(); i++)
    {
        length = length + abs(black[i]-red[i]);
    }
    return length;
}

int main()
{
    int n;
    cout<<"Enter the number of balls->";
    cin>>n;
    vector<int> black;
    vector<int> red;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the coordinates of black ball no "<<i+1<<" -> ";
        int x;
        cin>>x;
        black.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the coordinates of red ball no "<<i+1<<" -> ";
        int x;
        cin>>x;
        red.push_back(x);
    }
    cout<<"Minimum length of wire required is "<<threading(black, red)<<endl;
    return 0;
}
