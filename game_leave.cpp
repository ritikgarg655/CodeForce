#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int> e[], int n,int x){
	vector<int> temp = e[x];
	int i =0 ;
	int max_index = 0 ;
	int max_comp = INT_MAX;
	for(auto it = e[x].begin(); it!=e[x].end();it++){
		e[x] = temp;
		cout<<e[x].size();
		e[x].erase(it);
		queue<int> q;
		q.push(x);
		int num = 0;
		bool visited[n] = {false};
		visited[x] = true;
		while(!q.empty()){
			num++;
			int node = q.front();
			// cout<<e[node].size();
			q.pop();
			for(int i=0;i<e[node].size() ;i++){
				if(!visited[e[node][i]]){
					visited[e[node][i]] = true;
					q.push(e[node][i]);
				}
			}
		}
		if(max_comp<num){
			num = max_comp;
			max_index = i;
		}
		i++;
	}
	return max_index;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n,x;cin>>n>>x;
		x--;
		vector<int> e[n];
		for(int i=0;i<n-1;i++){
			int a,b;cin>>a>>b;
			e[a-1].push_back(b-1);
			e[b-1].push_back(a-1);
		}
		// BFS
		queue<int> q;
		q.push(x);
		int num = 0;
		bool visited[n] = {false};
		vector<int>::iterator it = e[x].begin();
		// cout<<e[x].size();
		int time = bfs(e,n,x);
		for(int i=0;i<time;i++){
			it++;
		}
		if(e[x].size()>0)
			e[x].erase(it);
		// cout<<e[x].size();
		visited[x] = true;
		while(!q.empty()){
			num++;
			int node = q.front();
			// cout<<e[node].size();
			q.pop();
			for(int i=0;i<e[node].size() ;i++){
				if(!visited[e[node][i]]){
					visited[e[node][i]] = true;
					q.push(e[node][i]);
				}
			}
		}
		if(num%2==0){
			cout<<"Ashish";
		}
		else{
			cout<<"Ayush";
		}
		cout<<endl;
	}
}