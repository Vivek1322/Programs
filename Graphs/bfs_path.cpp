#include <bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int, vector<int>> &edges, int n, int source, int goal, vector<bool> &vis, vector<int> &ans){
    if(source == goal){
        ans.push_back(source);
        return true;
    }

    queue<int> q;
    q.push(source);
    vis[source] = true;

    vector<int> parent(n, -1);
    parent[source] = -1;

    bool flag = false;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto it : edges[curr]){
            if(!vis[it]){
                parent[it] = curr;
                q.push(it);
                vis[it] = true;
                if(it == goal){
                    flag = true;
                    break;
                }
            }
        }
    }

    if(flag){
        int i = goal;
        while(i != -1){
            ans.push_back(i);
            i = parent[i];
        }
        return true;
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
    bool exists = bfs(edges, n, source, goal, vis, ans);
    
    cout<<'\n';
    if(exists){
        reverse(ans.begin(), ans.end());
        cout<<"Using BFS Traversal, path between the source vertex "<<source<<" and goal vertex "<<goal<<" for the given graph is as follows :- \n";
        int len = ans.size();
        for(int i = 0; i<len; i++){
            cout<<ans[i]<<"  ";
        }
    }
    else{
        cout<<"No path exists between the source vertex "<<source<<" and goal vertex "<<goal<<" for the given graph.";
    }
}
