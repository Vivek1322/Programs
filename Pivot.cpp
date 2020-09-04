#include<iostream>
using namespace std;
void pivot(int arr[],int start,int end)
{
    int mid=(start+end)/2;
    if(end>=mid){
        if(mid>start && arr[mid]<arr[mid-1])
            cout<<"Pivot element is present at index "<<mid-1<<" .\n";
        else if(mid<end && arr[mid]>arr[mid+1])
            cout<<"Pivot element is present at index "<<mid<<" .\n";
        else if(arr[start]>=arr[mid])
            pivot(arr,start,mid-1);
        else
            pivot(arr,mid+1,end);
    }
    else
        cout<<"There is no pivot element.\n";
}

int main()
{
    cout<<"Enter the size of the array.\n";
    int n;
    cin>>n;
    cout<<"Enter the elements of the rotated sorted array.\n";
    int *arr = new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    pivot(arr,0,n-1);

    return 0;
}
