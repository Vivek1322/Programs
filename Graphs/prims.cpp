#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &dis, vector<bool> &vis, int n){
    int minVertex = -1;
    for(int i = 0; i<n; i++){
        if(!vis[i] && (minVertex == -1 || dis[minVertex] > dis[i])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(vector<vector<int>> &A, int n){
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);
    vector<int> parent(n, -1);

    dis[0] = 0;
    parent[0] = -1;

    for(int i = 0; i<n; i++){
        int minVertex = find(dis, vis, n);
        vis[minVertex] = true;
        for(int j = 0; j<n; j++){
            if(A[minVertex][j] != 0 && !vis[j]){
                if(A[minVertex][j] < dis[j]){
                    dis[j] = A[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i<n; i++){
        cout<<parent[i]<<"->"<<i<<" weighted "<<A[i][parent[i]]<<endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;
    vector<vector<int>> A(n, vector<int> (n, 0));

    for(int i = 0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        A[s][d] = w;
        A[d][s] = w;
    }

    prims(A, n);  

    return 0;
}
