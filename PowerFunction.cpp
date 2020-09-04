#include<bits/stdc++.h>
using namespace std;

int calculateRec(int x, int y)
{
    if(y==0)
        return 1;
    if(y%2==0)
        return calculateRec(x, y/2)*calculateRec(x, y/2);
    else
        return x*calculateRec(x, y-1);
}

int calculate(int x, int y)
{
    if(y==0)
        return 1;
    int ans = 1;
    while(y>0)
    {
        if(y%2==0)
        {
            y /= 2;
            x *= x;
        }
        else
        {
            y--;
            ans *= x;
        }
    }
    return ans;
}

int main()
{
    int x, y;
    cout<<"Enter x -> ";
    cin>>x;
    cout<<"Enter y -> ";
    cin>>y;

    cout<<x<<" raise to power "<<y<<" = "<<calculateRec(x, y)<<endl;
    cout<<x<<" raise to power "<<y<<" = "<<calculate(x, y)<<endl;
    return 0;
}

