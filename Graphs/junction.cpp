#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector< pair<int,int> >adj[N];
int n,dist[N];
int calc(int src,int dst){
    for(int i=1;i<=n;i++)dist[i]=1e9;
    dist[src]=0;
    set< pair<int,int> > s;
    s.insert({0,src});
    while(!s.empty()){
		auto x = *(s.begin());
		s.erase(x);
		for(auto it:adj[x.second]){
			if(dist[it.first] > dist[x.second] + it.second){
				s.erase({dist[it.first], it.first});
				dist[it.first]=dist[x.second] + it.second;
				s.insert({dist[it.first], it.first});
			}
		}
    }
	return dist[dst];
}
int minCostPath(int g_nodes, vector<int> g_from, vector<int> g_to,vector<int> g_weight,int x,int y){
    n = g_nodes;
    for(int i=1;i<=n;i++)adj[i].clear();
	for(int i=0;i<g_from.size();i++){
    	adj[g_from[i]].push_back({g_to[i],g_weight[i]});
		adj[g_to[i]].push_back({g_from[i],g_weight[i]});
	}
	return calc(1,x) + calc(x,y) + calc(y,n);
}

int main() {
    int n = 5;
    vector<int> A = {1, 2, 3, 4, 3};
    vector<int> B = {2, 3, 4, 5, 5};
    vector<int> C = {3, 4, 6, 1, 10};
    int x = 2;
    int y = 3;
    cout<<minCostPath(n, A, B, C, x, y);
}
