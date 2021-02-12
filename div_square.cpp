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

int bs_ae(int start,int end,vector<int> &curr_hor,int val){
	int mid = (start+end)/2;
	id(start>=end){
		return start;
	}
	if(curr_hor[mid]==val){
		return mid;
	}
	else if(curr_hor[mid]<val){
		return bs_ae(mid+1,end,curr_hor,val);
	}
	else{
		return bs_ae(start,mid-1,curr_hor,val);
	}
}
int bs_be(int start,int end,vector<int> &curr_hor,int val){
	int mid = (start+end)/2;
	id(start>=end){
		return start;
	}
	if(curr_hor[mid]>val){
		return bs_ae(mid+1,end,curr_hor,val);
	}
	else{
		return bs_ae(start,mid-1,curr_hor,val);
	}
}

void solve(){
	int n,m;
	// n = 1;
	cin>>n>>m;
	int arr[n];
	vector<pair<ppi,int>> hor,ver;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		hor.push_back({a,{b,c}});
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ver.push_back({a,{b,c}});
	}
	map<int,vector<int>> start,end;
	for(int i=0;i<n;i++){
		if(start.find(hor[i].second.first)==start.end()){
			vector<int> v;
			start[hor[i].second.first] = v;	
		}
		if(end.find(hor[i].second.first)==end.end()){
			vector<int> v;
			end[hor[i].second.first] = v;	
		}
		start[hor[i].second.first].push_back(hor[i].first);
		end[hor[i].second.second].push_back(hor[i].first);
	}
	vector<int> curr_hor;
	curr_hor.push_back(0);
	long long int ans = 0;
	for(int i=0;i<m;i++){
		sort(curr_hor.begin(),curr_hor.end());
		int start_i = ver.second.first;
		int end_i  = ver.second.second;
		int inter = bs_be(0,curr_hor.size(),curr_hor,end_i) - bs_ae(0,curr_hor.size(),curr_hor,start_i);
		ans = (ans+inter);
		for()
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