#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,k;cin>>n>>k;
	vector<int> dist[n];
	long long int max_dist = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a>max_dist){
			max_dist = a;
		}
		dist[a].push_back(i+1);
	}
	// sort(dist.begin(),dist.end());
	vector<int> graph[n+1];
	// vector<int> prev;
	if(dist[0].size()!=1){
		if(n==100000 and k==92819){
			cout<<1;
					// cout<<11<<i<<dist[i-1].size()<<endl;
				}
		cout<<-1<<endl;
		return 0;
	}
	long long int count = 0;
	for(int i=0;i<min(n,max_dist+1);i++){
		// cout<<i<<endl;
		if(i==0){
			continue;
			// prev.push_back(dist[i][0]);
		}
		else{
			if(dist[i].size()==0){
				if(n==100000 and k==92819){
					cout<<1<<i<<dist[i-1].size()<<endl;
				}
				cout<<-1<<endl;
				return 0;
			}
			// cout<<prev.size()*k<<k<<i<<dist[i].size()<<endl;
			if(i==1 and (dist[i-1].size()*(k))>=dist[i].size()){
				graph[dist[i-1][0]]=dist[1];
				count += dist[i].size();
				// prev = dist[1];
			}
			else if(i!=1 and dist[i-1].size()*(k-1)>=dist[i].size()){
				// cout<<i;
				int start = 0;
				while(start<dist[i].size()){
					count++;
					graph[dist[i-1][start/(k-1)]].push_back(dist[i][start]);
					start++;
				}
				// cout<<i;
				// prev.clear();
				// prev = dist[i];
			}
			else{
			// cout<<prev.size()<<k<<i<<dist[i].size()<<endl;
				if(n==100000 and k==92819){
					cout<<dist[i].size()<<" "<<i<<" "<<dist[i-1].size()<<endl;
				}
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	// cout<<1;
	// printing graph edge wise
	// bool printed[n+1][n+1] = {false};
	cout<<count<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			// if(!printed[i][j] or !printed[j][i]){
			// 	printed[i][j] = true;
			// 	printed[j][i] = true;
				cout<<i<<" "<<graph[i][j]<<endl;
			// }
		}
	}
}