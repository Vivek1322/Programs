#include<bits/stdc++.h>
using namespace std;

int trappedWater(int * a, int n)
{
    int * left = new int [n];
    int * right = new int [n];
    left[0] = a[0];
    right[n-1] = a[n-1];
    int ans = 0;
    for(int i=1; i<n; i++)
        left[i] = max(left[i-1], a[i]);
    for(int i=n-2; i>=0; i--)
        right[i] = max(right[i+1], a[i]);
    for(int i=0; i<n; i++)
        ans += min(left[i], right[i]) - a[i];
    return ans;
}

int trappedWaterOptimize(int * a, int n)
{
    int ans = 0;
    int left_max = 0;
    int right_max = 0;
    int low = 0, high = n-1;

    while(low<=high)
    {
        if(a[low]<a[high])
        {
            if(a[low]>left_max)
                left_max = a[low];
            else
                ans += left_max - a[low];
            low++;
        }
        else
        {
            if(a[high]>right_max)
                right_max = a[high];
            else
                ans += right_max - a[high];
            high--;
        }
    }

    return ans;
}

int main()
{
    cout<<"Enter the size of the array->";
    int n;
    cin>>n;
    int * a = new int[n];
    cout<<"Enter the elements of the array->";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }
    cout<<"Total units of rain water trapped -> "<<trappedWater(a, n)<<endl;
    cout<<"Total units of rain water trapped -> "<<trappedWaterOptimize(a, n)<<endl;

    return 0;
}
