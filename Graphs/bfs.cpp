#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &edges, int n, int start, vector<bool> &vis){
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        cout<<curr<<"  ";

        for(auto it : edges[curr]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }

    return;
}

int main() {
    int n;
    cout<<"Enter number of vertices :- ";
    cin>>n;
    vector<bool> vis(n, false);

    int e;
    cout<<"Enter number of edges :- ";
    cin>>e;

    unordered_map<int, vector<int>> edges;
    for(int i = 0; i<e; i++){
        cout<<"Enter edge "<< i + 1 <<" => ";
        int u, v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int start;
    cout<<"Enter starting vertex :- ";
    cin>>start;

    cout<<'\n';
    cout<<"Breadth First Search of given graph is as follows :- \n";
    bfs(edges, n, start, vis);

    return 0;
}
