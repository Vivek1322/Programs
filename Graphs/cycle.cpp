#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int s;
        int d;
};

int find(vector<int> &parent, int i){
    if(i == parent[i]){
        return i;
    }
    return find(parent, parent[i]);
}

void cycle(vector<Edge> &A, int n, int e){
    vector<int> parent(n, 0);
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }

    int i = 0;
    while(i < e){
        int s = A[i].s;
        int d = A[i].d;

        int sp = find(parent, s);
        int dp = find(parent, d);

        if(sp == dp){
            cout<<"Cycle Present\n";
            return;
        }

        parent[sp] = dp;

        i++;
    }
    cout<<"No cycle present\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;
    
    vector<Edge> A(e);
    for(int i = 0; i<e; i++){
        int s, d;
        cin>>s>>d;
        A[i].s = s;
        A[i].d = d;
    }

    cycle(A, n, e);

    return 0;
}
