#include <bits/stdc++.h>
using namespace std;

bool cycleUtil(map<int, vector<int>> &A, vector<bool> &vis, vector<bool> &rec, int sv){
    if(!vis[sv]){
        vis[sv] = true;
        rec[sv] = true;
        
        for(auto i = A[sv].begin(); i != A[sv].end(); i++){
            if(!vis[*i] && cycleUtil(A, vis, rec, *i)){
                return true;
            }
            else if(rec[*i]){
                return true;
            }
        }
    }
    rec[sv] = false;
    return false;
}

void cycle(map<int, vector<int>> &A, int n){
    vector<bool> vis(n, false);
    vector<bool> rec(n, false);
    for(int i = 0; i<n; i++){
        if(cycleUtil(A, vis, rec, i)){
            cout<<"Cycle Present\n";
            return;
        }
    }
    cout<<"No cycle present\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;
    map<int, vector<int>> A;

    for(int i = 0; i<e; i++){
        int a, b;
        cin>>a>>b;
        A[a].push_back(b);
    }

    for(auto it = A.begin(); it != A.end(); it++){
        cout<<it->first<<"->";
        for(int j = 0; j<it->second.size(); j++){
            cout<<it->second[j]<<", ";
        }
        cout<<endl;
    }

    cycle(A, n);

    return 0;
}
