#include<bits/stdc++.h>
using namespace std;

void print(priority_queue<int, vector<int>, greater<int> > &p)
{
    int top = p.top();
    p.pop();
    cout<<top<<" ";
    if(!p.empty())
        print(p);
    p.push(top);
}

int main()
{
    cout<<"Enter the number of top elements you would like to query->";
    int n;
    cin>>n;
    cout<<"Enter -1 to query, 0 to quit and any other number to consider in the stream."<<endl;

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++)
        pq.push(0);

    while(true)
    {
        cout<<"Enter the number->";
        int k;
        cin>>k;

        if(k==-1)
        {
            ///show the top n items
            cout<<"The top "<<n<<" elements are->";
            print(pq);
            cout<<endl;
        }
        else if (k==0)
        {
            /// exit the program
            break;
        }
        else
        {
            ///enter into the heap
            if(k>pq.top())
            {
                pq.pop();
                pq.push(k);
            }
        }

    }

    return 0;
}
