#include<bits/stdc++.h>
using namespace std;

void dfs(pair<int,int> mem[],int index,int &n,vector<int> &path){
	static vector<vector<int>> ans;
	static bool visited[200001] = {false};
	if(index==n) {
		if(ans.size()<2)
			ans.push_back(path);
		return;
	}
	for(int i=mem[index].first;i<=mem[index].second;i++){
		if(!visited[i-1] and ans.size()<=1){
			path.push_back(i);
			visited[i-1] = true;
			dfs(mem,index+1,n,path);
			visited[i-1] = false;
			path.pop_back();
		}
	}
	if(index==0){
		if(ans.size()==1){
			cout<<"YES"<<endl;
			for(int i=0;i<ans[0].size();i++){
				cout<<ans[0][i]<<" ";
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
			for(int i=0;i<ans[0].size();i++){
				cout<<ans[0][i]<<" ";
			}
			cout<<endl;
			for(int i=0;i<ans[1].size();i++){
				cout<<ans[1][i]<<" ";
			}
			cout<<endl;			
		}
	}
	return;
}


int main(){
	int n;
	cin>>n;
	pair<int,int> mem[n];
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		mem[i] = make_pair(a,b);
	} 
	sort(mem,mem + n);
	vector<int> path;
	dfs(mem,0,n,path);
}