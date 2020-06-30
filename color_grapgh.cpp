#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>  g[],int n,set<int> nearby_color[],int c[],int prev_col,int index,bool	 visited[]){
	// static bool visited[100001] = {false};
	visited[index] = true;
	// if(prev_col!=-1){
	// 	nearby_color[c[index]].push(prev_col);
	// 	nearby_color[prev_col].push(c[index]);
	// }
	for(int i=0;i<g[index].size();i++){
		if(c[index]!=c[g[index][i]]){
			nearby_color[c[index]].insert(c[g[index][i]]);
			nearby_color[c[g[index][i]]].insert(c[index]);
		}
		if(!visited[g[index][i]]){
			visited[g[index][i]] = true;
			dfs(g,n,nearby_color,c,c[index],g[index][i],visited);
		}
	}
}

int main(){
	int n,m;cin>>n>>m;
	int c[n];
	set<int> uniq_c;
	vector<int> g[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
		uniq_c.insert(c[i]);
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	set<int> nearby_color[100001];
	bool visited[n] = {false};
	for(int i=0;i<n;i++){
		if(!visited[i]){

			dfs(g,n,nearby_color,c,-1,i,visited);
		}
	}
	int max = -1;
	// cout<<max;
	set<int>::iterator it = uniq_c.begin();
	int col = *it;
	// max = nearby_color[*it].size();
	for(;it!=uniq_c.end();it++){
			// cout<<(int)nearby_color[*it].size()<<*it<<endl;
		if(max<(int)nearby_color[*it].size()){
			max = nearby_color[*it].size();
			col = *it;
		}
	}
	cout<<col<<endl;
}