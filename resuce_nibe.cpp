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



int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n,k;
	// t = 1;
	cin>>n>>k;
	map<int,pair<int,int>> m; // come, end
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		m[l].first++;
		// if(l!=r)
		// m[r-1].second++;
		// else
			m[r].second++;
	}
	long long int ans = 0LL;
	int curr_post = 0;
	for(auto it = m.begin();it!=m.endk();it++){
		if(it->second.first>0){
			curr_post+=it->second.first;
			curr_post%=998244353;
			if(curr_post>=k){
				cout<<it->second.first<<" 0"<<endl;
				ans=(ans+curr_post-k+1)%998244353;
			}
		}
		if(it->second.second>0){
				cout<<it->second.first<<" 1"<<endl;
			curr_post= (curr_post -  it->second.second)%998244353;
		}
	}
	cout<<ans;
}