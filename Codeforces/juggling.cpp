#include <bits/stdc++.h>
using namespace std;

bool solve(vector<string> &A){
    int n = A.size();
    vector<int> count(26, 0);
    int total = 0;
    for(int i = 0; i<n; i++){
        int len = A[i].length();
        total += len;
        for(int j = 0; j<len; j++){
            count[A[i][j] - 'a']++;
        }
    }
    if(total % n != 0){
        return false;
    }
    for(int i = 0; i<26; i++){
        if(count[i] % n != 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> A(n);
        for(int i = 0; i<n; i++){
            cin>>A[i];
        }
        if(solve(A)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
