#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))

int find_cc(vi graph[],int graph_cc[],int node,bool visited[],int max_count[],int n){
	if(visited[node]){
		return 0;
	}
	int conc = 0;
	int ans = 0;
	visited[node] = true;
	int count_max = 0;
	for(int i=0;i<graph[node].size();i++){ 
		int a= find_cc(graph,graph_cc,graph[node][i],visited,max_count,n);
		if(ans<a){
			count_max = 1;
			ans = a;
		}
		else if(ans==a){
			count_max++;
		}
		conc+=a;
	}
	if(ans<n-conc-1){
		ans = n-conc-1;
		count_max = 1;
	}
	else if(ans==n-conc-1){
		count_max++;
	}
	graph_cc[node] = ans;
	max_count[node] = count_max;
	return conc + 1;
}

void solve(){
	int i,j,k,q,l;
	int n;
	// n = 1;
	cin>>n;
	int arr[n];
	vi graph[n];
	rep(i,0,n-1){
		int a,b;
		cin>>a>>b;a--;b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	bool visited[n] = {false};
	int graph_cc[n];
	int max_count[n]= {0};
	int a = find_cc(graph,graph_cc,0,visited,max_count,n);
	int max_val =INT_MAX;
	int ans_ind = 0;
	vi contain_max_cc_posb;
	rep(i,0,n){
		if(max_val>graph_cc[i]){
			contain_max_cc_posb.clear();
			max_val = graph_cc[i];
			ans_ind  = i;
			contain_max_cc_posb.pb(i);
		}
	 	else if(max_val ==graph_cc[i]){
			contain_max_cc_posb.pb(i);
	 	}
	}
	
	cout<<contain_max_cc_posb.size()<<endl;
	cout<<ans_ind;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}