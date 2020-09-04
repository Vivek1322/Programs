#include <bits/stdc++.h>
using namespace std;

void bridgesUtil(unordered_map<int, vector<int>> &m, int curr, vector<int> &disc, vector<int> &low, vector<bool> &vis, int parent, int &t){
    vis[curr] = true;
    t++;
    disc[curr] = t;
    low[curr] = t;

    int n = m[curr].size();
    for(int i = 0; i<n; i++){
        int v = m[curr][i];
        if(!vis[v]){
            bridgesUtil(m, v, disc, low, vis, curr, t);
            low[curr] = min(low[curr], low[v]);

            if(low[v] > disc[curr]){
                cout<<curr<<"->"<<v<<endl;
            }
        }
        else if(v != parent){
            low[curr] = min(low[curr], disc[v]);
        }
    }
}

void bridges(unordered_map<int, vector<int>> &m, int n){
    vector<int> disc(n, INT_MAX);
    vector<int> low(n, INT_MAX);
    vector<bool> vis(n, false);
    int parent = -1;
    int t = 0;

    for(int i = 0; i<n; i++){
        if(!vis[i]){
            bridgesUtil(m, i, disc, low, vis, parent, t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;
    unordered_map<int, vector<int>> m;

    for(int i = 0; i<e; i++){
        int s, d;
        cin>>s>>d;
        m[s].push_back(d);
        m[d].push_back(s);
    }

    bridges(m, n);

    return 0;
}
