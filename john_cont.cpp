#include<bits/stdc++.h>
using namespace std;

int find_cy_size(vector<int> graph[],int n){
	bool visited[n] = {false};
	// bfs to find cycle;
	
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> graph[n];
	vector<int> num[n+1];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int uniq = 0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(num[a].size()==0){
			num[a].push_back(1);
			uniq++;
		}
		else{
			num[a][0]++;
		}
	}
	// req is max size of cycle
	int cy_size = find_cy_size(vector<int> graph,n);
	if(uniq)
}