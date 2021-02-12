#include<bits/stdc++.h>
using namespace std;

bool isconnected(int node_1,int node_2,int node, vector<int> graph[],bool visited[]){
	for(int i=0;i<graph[node].size();i++){
		if(!visited[graph[node][i]]){
			visited[graph[node][i]] = true;
			if(node!=node_1 and node_2==graph[node][i]){
				return true;
			}
			else{
				bool temp_ans = isconnected(node_1,node_2,graph[node][i],graph,visited);
				if(temp_ans){
					return true;
				}
			}
		}
	}
	return false;
}

int main(){
	int n,m,q;cin>>n>>m>>q;
	vector<int> graph[n];
	vector<pair<int,int>> q_graph[n];
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
		q_graph[z-1].push_back(make_pair(x-1,y-1));
	}
	bool query[q] = {true};
	for(int i=0;i<q;i++){
		int w;cin>>w;
		// cout<<w-1;
		int node_1 = q_graph[w-1][0].first;
		int node_2 = q_graph[w-1][0].second;
		bool visited[n] = {false};
		if(!isconnected(node_1,node_2,node_1,graph,visited)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}