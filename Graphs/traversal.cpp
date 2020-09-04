#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<vector<int>> &A, int n, int sv, vector<bool> &vis){
    cout<<sv<<" ";
    vis[sv] = true;

    for(int i = 0; i<n; i++){
        if(A[sv][i] == 1 && !vis[i]){
            dfsUtil(A, n, i, vis);
        }
    }
    return;
}

void dfs(vector<vector<int>> &A, int n, int sv){
    vector<bool> vis(n, false);
    dfsUtil(A, n, sv, vis);
    return;
}

void bfs(vector<vector<int>> &A, int n, int sv){
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(sv);
    vis[sv] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout<<curr<<" ";

        for(int i = 0; i<n; i++){
            if(A[curr][i] == 1 && !vis[i]){
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int> (n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>A[i][j];
        }
    }

    int sv;
    cin>>sv;

    bfs(A, n, sv);
    cout<<"\n";
    dfs(A, n, sv);

    return 0;
}
