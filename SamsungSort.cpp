#include <bits/stdc++.h>
using namespace std;

// void sort(vector<int> &v){
// 	int n = v.size();
// 	int i=0;
// 	int j=1;
// 	while(1){
// 		while(i<n && v[i]%2==0)
// 			i = i+2;
// 		while(j<n && v[j]%2!=0)
// 			j = j+2;
// 		if(i<n && j<n)
// 			swap(v[i], v[j]);
// 		else
// 			break;
// 	}
// }

// void sort(vector<int> &v){
// 	int n = v.size();
// 	int i = 0;
// 	int j = 1;
// 	int k = 0;
// 	while(k<n){
// 		if(k%2==0){
// 			if(v[k]%2==0){
// 				k++;
// 				continue;
// 			}
// 			else{
// 				swap(v[k], v[j]);
// 				j = j+2;
// 			}
// 		}
// 		else{
// 			if(v[k]%2!=0){
// 				k++;
// 				continue;
// 			}
// 			else{
// 				swap(v[k], v[i]);
// 				i = i+2;
// 			}
// 		}
// 		k++;
// 	}
// }

void sort(vector<int> &v){
	int n = v.size();
	for(int i=0; i<n; i++){
		if(i%2==0){
			if(v[i]%2==0)
				continue;
			else{
				int j = i+1;
				int val = v[i];
				while(j<n){
					if(v[j]%2==0)
						break;
					int temp = v[j];
					v[j] = val;
					val = temp;
					j++;
				}
				v[i] = v[j];
				v[j] = val;
			}
		}
		else{
			if(v[i]%2!=0)
				continue;
			else{
				int j = i+1;
				int val = v[i];
				while(j<n){
					if(v[j]%2!=0)
						break;
					int temp = v[j];
					v[j] = val;
					val = temp;
					j++;
				}
				v[i] = v[j];
				v[j] = val;
			}
		}
	}
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> v(n, 0);
	for(int i=0; i<n; i++)
		cin>>v[i];
	sort(v);
	for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
	return 0;
}
