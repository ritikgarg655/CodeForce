// #include<bits/stdc++.h>
// using namespace std;

// void find_min_path(vector<int> v[],int index,int length,bool visited[],int dst,int &min_lenght,vector<pair<int,int>> path,vector<vector<pair<int,int>>> &sort_path){
// 	if(index==dst){
// 		// cout<<index;
// 		if(min_lenght==-1){
// 			min_lenght = length;
// 			sort_path.push_back(path);
// 		}
// 		else if (min_lenght>length){
// 			min_lenght = length;
// 			sort_path.clear();
// 			sort_path.push_back(path);
// 		}
// 		else if (min_lenght == length){
// 			sort_path.push_back(path);
// 		}
// 		return ;
// 	}
// 	// int ans= -1;
// 	for(int i=0;i<v[index].size();i++){
// 		if(!visited[v[index][i]]){
// 			visited[v[index][i]] = true;
// 			path.push_back(make_pair(index,v[index][i]));
// 			find_min_path(v,v[index][i],length+1,visited,dst,min_lenght,path,sort_path);
// 			visited[v[index][i]] = false;
// 			path.pop_back();	
// 		}
// 	}

// 	return;
// }

// int main(){
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,m,a,b,c;
// 		cin>>n>>m>>a>>b>>c;
// 		int p[m];
// 		for(int i=0;i<m;i++) cin>>p[i];
// 		vector<int> v[n];
// 		for(int i=0;i<m;i++){
// 			int q,w;
// 			cin>>q>>w;
// 			v[q-1].push_back(w-1);
// 			v[w-1].push_back(q-1);
// 		}
// 		bool visited_1[n] = {false};
// 		bool visited_2[n] = {false};
// 		int length_1 = -1,length_2 = -1;
// 		visited_1[a-1] = true;
// 		visited_2[b-1] = true;
// 		vector<vector<pair<int,int>>> all_sort_path_1,all_sort_path_2;
// 		vector<pair<int,int>> path;
// 		find_min_path(v,a-1,0,visited_1,b-1,length_1,path,all_sort_path_1);
// 		find_min_path(v,b-1,0,visited_2,c-1,length_2,path,all_sort_path_2);
// 		int max_common = 0;
// 		int v_1 = 0;
// 		int v_2 = 0;
// 		for(int i=0;i<all_sort_path_1.size();i++){
// 			for(int j=0;j<all_sort_path_2.size();j++){
// 				int temp_comom = 0;
// 				for(int k=0;k<all_sort_path_1[i].size();k++){
// 					if(find(all_sort_path_2[j].begin(),all_sort_path_2[j].end(),all_sort_path_1[i][k])!=all_sort_path_2[j].end()){
// 						temp_comom++;
// 					}
// 				}
// 				if(temp_comom>=max_common){
// 					v_1 = i;
// 					v_2 = j;
// 				}
// 			}
// 		}
// 		vector<pair<int,int>> sort_path_1 = all_sort_path_1[v_1],sort_path_2 = all_sort_path_2[v_2];
// 		// cout<<length_2<<endl;
// 		// for(int i=0;i<sort_path_2.size();i++){
// 		// 	cout<<sort_path_2[i].first<<sort_path_2[i].second<<endl;
// 		// }
// 		// for(int i=0;i<sort_path_1.size();i++){
// 		// 	cout<<sort_path_1[i].first<<sort_path_1[i].second<<endl;
// 		// }
// 		// for(int i=0;i<sort_path_2.size();i++){
// 		// 	cout<<sort_path_2[i].first<<sort_path_2[i].second<<endl;
// 		// }
// 		int commmon_apth = 0;
// 		for(int i=0;i<sort_path_1.size();i++){
// 			// cout<<i;
// 			if(find( sort_path_2.begin(), sort_path_2.end() ,make_pair(sort_path_1[i].first,sort_path_1[i].second))!=sort_path_2.end()){
// 				commmon_apth++;
// 			}
// 			else if (find( sort_path_2.begin(), sort_path_2.end() ,make_pair(sort_path_1[i].second,sort_path_1[i].first))!=sort_path_2.end()){
// 				commmon_apth++;
// 			}
// 		}
// 		// cout<<commmon_apth<<endl;
// 		sort(p,p+m);
// 		int ans = 0;
// 		int index= 0;
// 		for(int i =0;i<commmon_apth;i++){
// 			ans+= p[index]*2;
// 			index++;
// 		}
// 		for(int i = 0;i< sort_path_1.size()- commmon_apth;i++){
// 			ans+= p[index];
// 			index++;
// 		}
// 		for(int i = 0;i< sort_path_2.size()- commmon_apth;i++){
// 			ans+= p[index];
// 			index++;
// 		}
// 		cout<<ans<<endl;
// 	}
// }
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int>> g;

void bfs(int s, vector<int> &d) {
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		--a, --b, --c;
		
		vector<int> p(m);
		for (auto &it : p) cin >> it;
		sort(p.begin(), p.end());
		vector<long long> pref(m + 1);
		for (int i = 0; i < m; ++i) {
			pref[i + 1] = pref[i] + p[i];
		}
		
		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		vector<int> da(n, INF), db(n, INF), dc(n, INF);
		bfs(a, da);
		bfs(b, db);
		bfs(c, dc);
		
		long long ans = 1e18;
		for (int i = 0; i < n; ++i) {
			if (da[i] + db[i] + dc[i] > m) continue;
			ans = min(ans, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
		}
		cout << ans << endl;
	}
	
	return 0;
}