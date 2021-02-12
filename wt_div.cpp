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

// #define pb push_back;
// #define mp make_pair;
// #define f first;
// #define s second;
// #define rep(i,a,b) for(int i=a;i<b;i++);
// #define repv(i,v) for(int i=0;i<v.size();i++);
// #define reps(i,s) for(int i=0;i<s.length();i++);
// #define allv(v) v.begin(),v.end();
// #define alla(arr,sz) arr,arr+sz;
// #define rev(v) reverse(allv(v));
// #define reva(a) reverse(alla(a));

int dfs(int index,vector<pair<int,int>> v[],bool visited[],int arr[],priority_queue<pair<int,pair<int,int>>> &pq,long long int &sums){
	if(visited[index]){
		return 0;
	}
	visited[index] = true;
	int sum = 0;
	for(int i=0;i<v[index].size();i++){

		int a= dfs(v[index][i].first,v,visited,arr,pq,sums);
		sum += a;
		pq.push({a*v[index][i].second,{v[index][i].second,a}});
		sums += a*v[index][i].second;
	}
	arr[index] = sum;
	return sum+1;
}

void solve(){
	int i,j,k,q,l;
	int n,s;cin>>n>>s;
	vector<pair<int,int>> v[n];
	for(int i=0;i<n-1;i++){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	int arr[n] = {0};
	bool visited[n] = {false};
	priority_queue<pair<int,pair<int,int>>> pq;
	long long int sum = 0LL;
	int temp = dfs(0,v,visited,arr,pq,sum);
	// cout<<temp<<endl;
	// cout<<sum<<endl;
	int ans= 0;
	while(sum>s){
		ans++;
		pair<int,pair<int,int>> p = pq.top();
		pq.pop();
		sum -= p.first - (p.second.first/2 * p.second.second);
		p.second.first  = p.second.first/2;
		p.first = p.second.first * p.second.second;
		pq.push(p);
	}
	cout<<ans<<endl;
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