#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter -1 to query for median, 0 to quit and any other number to enter in the stream."<<endl;
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int> > q;
    p.push(INT_MIN);
    q.push(INT_MAX);
    while(true)
    {
        int n;
        cout<<"Enter the element->";
        cin>>n;
        int ptop = p.top();
        int qtop = q.top();
        int p1 = p.size();
        int q1 = q.size();

        if(n==-1)
        {
            ///show the median
            if(p1==q1 || p1>q1)
                cout<<"Median->"<<ptop<<endl;
            else
                cout<<"Median->"<<qtop<<endl;
        }
        else if(n==0)
        {
            break;
        }
        else
        {
            ///insert in one of the heaps
            if(n<ptop)
                p.push(n);
            else
                q.push(n);
        }

        if(p1-q1>1)
        {
            p.pop();
            q.push(ptop);
        }
        else if (q1-p1>1)
        {
            q.pop();
            p.push(qtop);
        }
    }

    return 0;
}
