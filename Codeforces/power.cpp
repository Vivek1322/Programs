#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &A){
    int n = A.size();
    ll ans = LONG_MAX;
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return A[0] - 1;
    }
    sort(A.begin(), A.end());
    ll len = ceil(pow(A[n-1], 1.0/(n-1)));

    for(int c = 1; c <= len; c++){
        ll temp = 0;
        ll val = 1;
        for(int i = 0; i<n; i++){
            temp += abs(A[i] - val);
            val = val * c;
        }
        ans = min(ans, temp);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> A(n);
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    cout<<solve(A);
    return 0;
}
