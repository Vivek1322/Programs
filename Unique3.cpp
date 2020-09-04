#include<iostream>
using namespace std;

int uniqueNumber(int *a,int n)
{
    int b[64]={0};
    for(int i=0;i<n;i++){
        int num=a[i];
        int j=0;
        while(num>0){
            b[j]+=num&1;
            num=num>>1;
            j++;
        }
    }
    int ans=0;
    int power=1;
    for(int i=0;i<64;i++){
        b[i]=b[i]%3;
        ans=ans+(b[i]*power);
        power*=2;
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of the array.\n";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the elements of the array.\n";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<uniqueNumber(arr,n);

    return 0;
}
