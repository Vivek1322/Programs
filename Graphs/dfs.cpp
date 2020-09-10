#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &edges, int n, int curr, vector<bool> &vis){
    vis[curr] = true;
    cout<<curr<<"  ";

    for(auto it : edges[curr]){
        if(!vis[it]){
            dfs(edges, n, it, vis);
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
    cout<<"Depth First Search of given graph is as follows :- \n";
    dfs(edges, n, start, vis);

    return 0;
}
