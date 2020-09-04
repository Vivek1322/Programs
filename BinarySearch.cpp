#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int num)
{
    if(end>=start){
        int mid = (start+end)/2;
        if(num==arr[mid])
            return mid;
        else if(num>arr[mid])
            return binarySearch(arr,mid+1,end,num);
        else if(num<arr[mid])
            return binarySearch(arr,start,mid-1,num);
    }
    return -1;
}

int main()
{
    cout<<"Enter the size of the array.\n";
    int n;
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of the sorted array.\n";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the element to be searched.\n";
    int var;
    cin>>var;

    int check=binarySearch(arr,0,n-1,var);

    if(check!=-1)
        cout<<"The searched element is present at index "<<check<<" in the array.\n";
    else
        cout<<"The searched element is not present in the array.\n";
    return 0;
}
