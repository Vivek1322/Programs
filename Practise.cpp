#include<bits/stdc++.h>
using namespace std;

int random(int n, int * a, int s)
{
    map<int, int> m;
    for(int i = 0; i<s; i++)
        m[a[i]] = 1;
    while(true)
    {
        int ans = (floor(rand()*100));
        ans = ans%n;
        if(m[ans]==1)
            continue;
        return ans;
    }
}

int maxSum(int * A, int n)
{
    int * a = new int [n];
    memset(a, 0, n);
    for(int i=0; i<=n; i++)
    {
        a[A[i]-1]++;
        if(a[A[i]-1]==2)
            return A[i];
    }
    return -1;

}
int main()
{
    int a[] = {31, 6, 8, 12, 22, 27, 1, 30, 11, 28, 36, 18, 17, 16, 24, 10, 21, 23, 2, 32, 33, 3, 9, 15, 13, 14, 23, 4, 20, 5, 34, 26, 19, 7, 25, 35, 29 };

    cout<<maxSum(a, 37);
 /*   int n, s;
    cin>>n>>s;

    int * a = new int [n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<5; i++)
    cout<<random(s, a, n)<<endl;
*/
    return 0;
}
