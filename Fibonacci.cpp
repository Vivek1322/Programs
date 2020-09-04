#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number to be searched.\n";
    cin>>n;
    int a=0,b=1,flag=0;
    int c=0;
    while(c<=n){
        if(n==c){
            cout<<"Number found.";
            flag=1;
            break;
        }
        c=a+b;
        a=b;
        b=c;
    }
    if(!flag)
        cout<<"Number not found";
    return 0;
}
