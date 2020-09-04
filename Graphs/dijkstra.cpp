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

int dijkstra(vector<vector<int>> &A, int n, int sv, int ev){
    vector<int> dis(n, INT_MAX);
    vector<bool> vis(n, false);

    dis[sv] = 0;

    for(int i = 0; i<n; i++){
        int minVertex = find(dis, vis, n);
        vis[minVertex] = true;
        if(minVertex == ev){
            return dis[minVertex];
        }
        for(int j = 0; j<n; j++){
            if(A[minVertex][j] != 0 && !vis[j]){
                int distance = dis[minVertex] + A[minVertex][j];
                if(distance < dis[j]){
                    dis[j] = distance;
                }
            }
        }
    }
    return dis[ev];
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

    int sv, ev;
    cin>>sv>>ev;

    cout<<"Shortest Path : "<<dijkstra(A, n, sv, ev)<<endl;

    return 0;
}
