#include<iostream>
using namespace std;

swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++){
        int key=i;
        for(int j=i+1;j<n;j++){
            if(arr[key]>arr[j]){
                key=j;
            }
        }
        if(key!=i){
            swap(arr[i],arr[key]);
        }
    }
}

int main()
{
    cout<<"Enter the number of elements.\n";
    int n;
    cin>>n;
    int *arr = new int[n];;
    cout<<"Enter the elements.\n";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SelectionSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
