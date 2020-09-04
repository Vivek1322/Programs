#include <bits/stdc++.h>
using namespace std;

class minHeap
{
    vector <int> v;

public:
    minHeap()
    {
        v.push_back(-1);
    }
    void push(int d)
    {
        v.push_back(d);
        int index = v.size()-1;
        int parent = index/2;
        while(index>0 && v[index]<v[parent])
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent/2;
        }

    }
    int getMin()
    {
        return v[1];
    }
    void pop()
    {
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        Heapify(1);
    }
    bool isEmpty()
    {
        return (v.size()==1);
    }
    void print()
    {
        cout<<endl;
        for(int i=1; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
private:
    void Heapify(int index)
    {
        int left = 2*index;
        int right = 2*index +1;
        int minIndex = index;

        if(left<v.size() && v[minIndex]>v[left])
            minIndex = left;
        if(right<v.size() && v[minIndex]>v[right])
            minIndex = right;
        if(minIndex!=index)
        {
            swap(v[index], v[minIndex]);
            Heapify(minIndex);
        }
    }
};

int main()
{
    minHeap h;
    int n;
    cout<<"Enter the size of the heap->";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter data->";
        int j;
        cin>>j;
        h.push(j);
    }
    h.print();
    for(int i=0; i<n; i++)
    {
        cout<<"Min element->"<<h.getMin()<<endl;
        h.pop();
        h.print();
    }
    return 0;
}
