// #include<bits/stdc++.h>
// using namespace std;

// int find_cy_size(vector<int> graph[],int n){
// 	bool visited[n] = {false};
// 	// bfs to find cycle;
	
// }

// int main(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> graph[n];
// 	vector<int> num[n+1];
// 	for(int i=0;i<m;i++){
// 		int a,b;
// 		cin>>a>>b;a--;b--;
// 		graph[a].push_back(b);
// 		graph[b].push_back(a);
// 	}
// 	int uniq = 0;
// 	for(int i=0;i<n;i++){
// 		int a;cin>>a;
// 		if(num[a].size()==0){
// 			num[a].push_back(1);
// 			uniq++;
// 		}
// 		else{
// 			num[a][0]++;
// 		}
// 	}
// 	// req is max size of cycle
// 	int cy_size = find_cy_size(vector<int> graph,n);
// 	if(uniq)
// }
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int n, m;
int ans[N];

int last[N];
vector <int> G[N];
vector <int> in[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i){
		int color;
		scanf("%d", &color);

		in[color].push_back(i);
		if(color > n){
			puts("-1");
			exit(0);
		}
	}
	
	vector <int> result;
	for(int i = 1; i <= n; ++i){
		for(auto u: in[i]){
			for(auto v: G[u])
				last[ans[v]] = u;
			
			ans[u] = 1;
			while(last[ans[u]] == u)
				++ans[u];
			
			if(ans[u] != i){
				puts("-1");
				exit(0);
			}
			
			result.push_back(u);
		}
	}
	
	for(int i = 0; i < n; ++i)
		printf("%d%c", result[i], i == n - 1 ? '\n' : ' ');
	return 0;
}