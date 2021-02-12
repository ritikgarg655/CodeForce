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
	ll n,m;
	// n = 1;
	cin>>n>>m;
	ll a[n],b[n],c[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	map<int,vector<int>> nf;
	map<int,int> mp;
	// bool lp = false;
	// stack<int> st;
	int li = 0;
	int ind = 0 ;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]!=a[i]){
			nf[b[i]].push_back(i);
			// li = i;
			// lp = true;
		}
		// else{
		mp[b[i]] = i;
		// }
	}
	int ansa[m];
	map<int,int> rem;
	vector<int> req;
	int cl = -1;
	int q1 = 0;
	for(int i=0;i<m;i++){
		cin>>c[i];
		ansa[i] = 0;
		if(nf.find(c[i])!=nf.end() and nf[c[i]].size()>0){
			ansa[i] = nf[c[i]][nf[(int)c[i]].size()-1]+1;
			nf[c[i]].pop_back();
			q1 = i;
			// cout<<i<<" ";
		}
		else{
			cl = i;
		}
	}
	bool ans = true;
	// cout<<mp[c[cl]];
	if(cl!=-1){
		if(cl!=m-1){
			ind = q1 ;
		}
		else if(mp.find(c[cl]) == mp.end()){
			ans = false;
		}
		else{
			ind = mp[c[cl]];
		}
		// else if(s.find(c[cl])==s.end()){
		// 	ans = false;
		// }
	}
	bool np = true;
	bool r = false;
	for(auto it = nf.begin();it!=nf.end();it++){
		if(it->second.size()!=0){
			ans = false;
		}
	}
	// for(int )
	// if(!blank){
	// 	if(!r){
	// 		ans = false;
	// 	}
	// }
	if(ans){
		cout<<"YES"<<endl;
		for(int  i = 0 ; i<m;i++){
			if(ansa[i] == 0){
				cout<<ind+1<<" ";
			}
			else{

				cout<<ansa[i]<<" ";
			}
		}
	}
	else{
		cout<<"NO";
	}
	cout<<endl;
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