#include<bits/stdc++.h>
using namespace std;

class Fruit
{
public:
    string name;
    int price;
    Fruit(string n, int p)
    {
        name = n;
        price = p;
    }
};

class myCompare
{
public:
    bool operator () (Fruit a, Fruit b)
    {
        if(a.price==b.price)
            return a.name<b.name;   ///Ascending order
        else
            return a.price>b.price;     ///Min heap
    }
};

int main()
{
    priority_queue<Fruit, vector<Fruit>, myCompare> pq;

    Fruit f1("Mango", 100);
    Fruit f2("Apple", 180);
    Fruit f3("Guava", 60);

    pq.push(f1);
    pq.push(f2);
    pq.push(f3);

    while(!pq.empty())
    {
        Fruit f = pq.top();
        pq.pop();
        cout<<f.name<<"->"<<f.price<<endl;
    }

    return 0;
}
