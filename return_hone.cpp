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



void solve(){
	// int i,j,k,q,l;
	int n,m;
	// n = 1;
	cin>>n>>m;
	int arr[n];
	int x,y,ex,ey;
	cin>>x>>y>>ex>>ey;
	vector<pair<int,int>> g;
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		g.push_back({a,b});
	}
	bool visited[n][n] = {false};
	stack<pair<int,pair<int,int>>> s;
	s.push({0,{x-1,y-1}});
	// visited[x-1][y-1] = true;
	for(int i=0;i<m;i++){
		s.push({0,g[i]});
		// visited[g[i].first] = true;
		// visited[g[i].second] = true;
	}
	// if(visited[n-1][n-1]){
	// 	cout<<"a";
	// }
	while(!s.empty()){
		auto cor = s.top();
		s.pop();
		if(cor.second.first == ex-1 and cor.second.second == ey-1){
			cout<<cor.first<<endl;
			break;
		}
		// cout<<cor.first<<endl;
		if(visited[cor.second.first][cor.second.second]){
			continue;
		}
		visited[cor.second.first][cor.second.second] = true;
		if(cor.second.first>0){
			// visited
			s.push({cor.first+1,{cor.second.first-1,cor.second.second}});
		}
		if(cor.second.second>0){
			s.push({cor.first+1,{cor.second.first,cor.second.second-1}});
		}
		if(cor.second.first<n-1){
			s.push({cor.first+1,{cor.second.first+1,cor.second.second}});
		}
		if(cor.second.second<n-1){
			s.push({cor.first+1,{cor.second.first,cor.second.second+1}});
		}
		// if((cor.second.first == x-1) or (cor.second.second == y-1)){
		// 	for(int i=0;i<m;i++){
		// 		s.push({cor.first,g[i]});
		// 	}
		// }
	}	
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}