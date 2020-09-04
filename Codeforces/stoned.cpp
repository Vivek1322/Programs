#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &A){
    int n = A.size();
    if(n == 1){
        return 1;
    }
    priority_queue<pair<int, int>> q;
    for(int i = 0; i<n; i++){
        q.push({A[i], i});
    }
    // for(int i = 0; i<n; i++){
    //     cout<<q.top().first<<" ";
    //     q.pop();
    // }

    pair<int, int> prev = {-1, -1};
    bool turn = 0;
    while(!q.empty()){
        pair<int, int> temp = q.top();
        temp.first--;
        q.pop();
        turn = !turn;
        if(prev.second != -1){
            q.push(prev);
        }
        prev = temp.first != 0 ? temp : make_pair(-1, -1);
    }

    return turn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i = 0; i<n; i++){
            cin>>A[i];
        }
        if(solve(A)){
            cout<<"T\n";
        }
        else{
            cout<<"HL\n";
        }
    }
    return 0;
}