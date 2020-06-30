// #include<bits/stdc++.h>
// using namespace std;

// void bfs(vector<int> g[],vector<vector<int>> &level,int &max_level,int n){
// 	// int current_level = 1;.
// 	queue<pair<int,int>> q; // node,level
// 	q.push(make_pair(0,1));
// 	bool visited[n] = {false};
// 	visited[0] = true;
// 	while(!q.empty()){
// 		int next_node,level_node;
// 		next_node = q.front().first;
// 		level_node = q.front().second;
// 		if(level_node>max_level){
// 			max_level = level_node;
// 			std::vector<int> v;
// 			level.push_back(v);
// 		}
// 		level[levelevel_node-1].push_back(next_node);
// 		q.pop();
// 		for(int i=0;i<g[next_node].size();i++){
// 			if(!visited[g[next_node][i]]){
// 				// cout<<g[next_node][i]<<level_node<<endl;
// 				visited[g[next_node][i]] = true;
// 				q.push(make_pair(g[next_node][i],level_node+1));
// 			}
// 		}
// 	}
// }

// bool find(int start_index,int end_index,int value,int arr[]){
// 	for(int i=start_index;i<=end_index;i++){
// 		// cout<<value<<arr[i]<<endl;
// 		if(arr[i]==value+1)
// 			return true;
// 	}
// 	return false;
// }

// int main(){
// 	int n;cin>>n;
// 	vector<int> g[n];
// 	for(int i=0;i<n-1;i++){
// 		int a,b;
// 		cin>>a>>b;
// 		g[a-1].push_back(b-1);
// 		g[b-1].push_back(a-1);a
// 	}
// 	int path[n];
// 	for(int i=0;i<n;i++){
// 		cin>>path[i];
// 	}
// 	vector<vector<int>> level;
// 	int max_level = 0;
// 	bfs(g,level,max_level,n);
// 	int prev_start = 0;
// 	bool done = true;
// 	for(int i=0;i<max_level;i++){
// 		// cout<<level[i]/	.size()<<prev_start<<endl;
// 		for(int j=0;j<level[i].size();j++){
// 			if(!find(prev_start,prev_start+level[i].size()-1,level[i][j],path)){
// 				// cout<<i<<j;
// 				done = false;
// 				break;
// 			}
// 		}
// 		prev_start = prev_start + level[i].size();
// 		if(!done) break;
// 	}
// 	if(done) cout<<"Yes";
// 	else cout<<"No";
// }
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int,int> pii;
    typedef pair<ll,ll> pll;
    typedef pair<ll,int> pli;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<pii> vpii;
    typedef vector<pll> vpll;
    #define F first
    #define S second
    typedef vector<pli> vpli;
    #define hell 1000000007
    #define mp make_pair
    #define pb push_back
    #define all(v) v.begin(),v.end() 
    #define tests int t; cin>>t; while(t--)
    #define take(a,b,c) for(b=0;b<c;b++) cin>>a[b];
    typedef long long ll;
    vector<int> ans,adj[200007];
    bool vis[200007];
    int inputorder[200007],relorder[200007];	
    bool cmp(int a,int b){
    	return relorder[a]<relorder[b];
    }
    int main()
    {	
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n,x,a,b,i,j;
    	cin>>n;
    	for(i=0;i<n-1;i++){	
    		cin>>a>>b;
    		adj[a].pb(b);
    		adj[b].pb(a);
    	}
    	for(i=0;i<n;i++){
    		cin>>inputorder[i];
    		relorder[inputorder[i]]=i;
    	}	
    	for(i=1;i<=n;i++)
    		sort(all(adj[i]),cmp);
    	queue<int> q;		
    	q.push(1);	
    	memset(vis,false,sizeof(vis));
    	while(!(q.empty())){
    		queue<int> temp;
    		while(!(q.empty())){
    			int x= q.front();
    			q.pop();
    			ans.pb(x);
    			vis[x]=true;
    			for(j=0;j<adj[x].size();j++)
    				if(vis[adj[x][j]]==false)
    					temp.push(adj[x][j]);
    			}
    		q=temp;			
    	}
    	for(i=0;i<n;i++)
    		if(inputorder[i]!=ans[i]){
    			cout<<"No"; return 0;}
    	cout<<"Yes";		
    		
        return 0;
    }