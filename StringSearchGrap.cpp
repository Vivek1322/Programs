#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n){
	if(i>=0 && i<m && j>=0 && j<m)
		return true;
	return false;
}

void dfs(vector<vector<char> > &A, string B, int curr_i, int curr_j, int m, int n, int index, int &count, vector<vector<bool> > &visited){
	if(index==B.length()){
		count++;
		return;
	}
	for(int i=curr_i-1; i<=curr_i+1; i++){
		for(int j=curr_j-1; j<=curr_j+1; j++){
			if(i==curr_i && j==curr_j)
				continue;
			if( isValid(i, j, m, n) && !visited[i][j] && A[i][j]==B[index]){
				visited[i][j] = true;
				dfs(A, B, i, j, m, n, index+1, count, visited);
				visited[i][j] = false;
			}
		}
	}
	return;
}

int solve(vector<vector<char> > &A, string B){
	int m = A.size();
	int n = A[0].size();
	int count = 0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(A[i][j]==B[0]){
				vector<vector<bool> > visited(m, vector<bool> (n, false));
				dfs(A, B, i, j, m, n, 1, count, visited);
			}
		}
	}
	return count;
}

int main() {
	// your code goes here
	int n, m;
	cin>>m>>n;
	vector<vector<char> > board(m, vector<char> (n, 'a'));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin>>board[i][j];
	}
	string word;
	cin>>word;
	cout<<solve(board, word);
	return 0;
}
