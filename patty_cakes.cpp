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


void solve(){
	int i,j,k,q,l;
	int n;cin>>n;int arr[n];
	map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		m[arr[i]-1]++;
	}
	int max = 0;
	int uniq = 0;
	int rep = 0;
	int sum = 0;
	int max_rep = 0;
	vector<int> v;
	for(auto it = m.begin();it!=m.end();it++){
		if(it->second > max){
			max = it->second;
			vector<int> temp;
			v = temp;
			max_rep = 0;
		}
		if(it->second == max and find(v.begin(), v.end(),it->first)==v.end()){
			v.push_back(it->first);
			// cout<<it->first;
			max_rep++;
		}
		if(it->second == 1){
			uniq++;
		}
		else{
			sum += it->second;
			rep++;
		}
	}
	long long int ans;
	// cout<<max<<sum<<max_rep<<uniq;
	if(rep!=0){
		ans = (uniq + sum-(max*max_rep))/(max-1) + max_rep -1;
	}
	else{
		ans = 0; 
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