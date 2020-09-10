#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>> &edges, int n, int curr, int goal, vector<bool> &vis, vector<int> &ans){
    vis[curr] = true;
    if(curr == goal){
        ans.push_back(curr);
        return true;
    }

    for(auto it : edges[curr]){
        if(!vis[it]){
            if(dfs(edges, n, it, goal, vis, ans)){
                ans.push_back(curr);
                return true;
            }
        }
    }

    return false;
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

    int source;
    cout<<"Enter source vertex :- ";
    cin>>source;

    int goal;
    cout<<"Enter goal vertex :- ";
    cin>>goal;

    vector<int> ans;
    bool exists = dfs(edges, n, source, goal, vis, ans);
    
    cout<<'\n';
    if(exists){
        reverse(ans.begin(), ans.end());
        cout<<"Using DFS Traversal, path between the source vertex "<<source<<" and goal vertex "<<goal<<" for the given graph is as follows :- \n";
        int len = ans.size();
        for(int i = 0; i<len; i++){
            cout<<ans[i]<<"  ";
        }
    }
    else{
        cout<<"No path exists between the source vertex "<<source<<" and goal vertex "<<goal<<" for the given graph.";
    }

    return 0;
}
