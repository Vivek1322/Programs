#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int s;
        int d;
        int w;
};

bool myCmp(Edge a, Edge b){
    return a.w < b.w;
}

int find(vector<int> &parent, int i){
    if(i == parent[i]){
        return i;
    }
    return find(parent, parent[i]);
}

void kruskal(vector<Edge> &A, int n, int e){
    vector<Edge> ans;
    vector<int> parent(n, 0);
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }

    sort(A.begin(), A.end(), myCmp);

    int i = 0;
    int count = 0;
    while(i < e && count < n-1){
        int s = A[i].s;
        int d = A[i].d;
        int w = A[i].w;

        int sp = find(parent, s);
        int dp = find(parent, d);

        if(sp != dp){
            parent[sp] = dp;
            ans.push_back(A[i]);
            count++;
            // cout<<A[i].s<<" -> "<<A[i].d<<" with weight "<<A[i].w<<endl;
        }
        
        i++;
    }

    for(int j = 0; j<n-1; j++){
        cout<<ans[j].s<<" -> "<<ans[j].d<<" with weight "<<ans[j].w<<endl;
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;
    
    vector<Edge> A(e);
    for(int i = 0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        A[i].s = s;
        A[i].d = d;
        A[i].w = w;
        // cout<<A[i].s<<" -> "<<A[i].d<<" with weight "<<A[i].w<<endl;
    }

    kruskal(A, n, e);

    return 0;
}
