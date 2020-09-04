#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool myCompare(pair<string,int> p1 , pair<string,int> p2)
{
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}
int main()
{
    int min;
    cout<<"Enter the minimum salary.\n";
    cin>>min;
    cout<<"Enter the total number of employees.\n";
    int n;
    cin>>n;
    pair<string,int> *emp = new pair<string,int> [n];
    cout<<"\nEnter the names and salaries of the employees.\n";

    for(int i=0;i<n;i++){
        cin>>emp[i].first;
        cin>>emp[i].second;
    }

    sort(emp,emp+n,myCompare);

    cout<<"\n\n";
    for(int i=0;i<n;i++){
            if(emp[i].second>min){
                    cout<<emp[i].first<<"  "<<emp[i].second<<"\n";
            }
    }

    return 0;
}

