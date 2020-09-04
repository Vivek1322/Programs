#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the length of the array.\n";
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the elements of the sorted array.\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key for which triplets are to be found.\n";
    cin>>key;
    int count=0;
    for(int k=0;k<n;k++){
            int i,j;
        for(i=k+1, j=n-1;i<j;){
            if(arr[i]+arr[j]+arr[k]==key){
                cout<<"Pair found is "<<arr[k]<<" "<<arr[i]<<" "<<arr[j]<<"\n";
                i++;
                j--;
                count++;
            }
            else if(arr[i]+arr[j]+arr[k]<key){
                i++;
            }
            else{
                j--;
            }
        }
    }
    if(count==0)
        cout<<"No such triplets found.\n";

    return 0;
}

