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


	void solve(int i){
		// int i,j,k,q,l;
		ll n;
		// n = 1;
		cin>>n;
		ll N = 1001;
		ll arr[n][n];
		ll sum[2*N+1] = {0};
		ll ans = 0;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>arr[i][j];
				sum[N+i-j]+=arr[i][j];
				if(sum[N+i-j] > ans){
					ans = sum[N+i-j];
				}
			}
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;

	}

	int main(){
		ios::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);
		int t;
		// t = 1;
		cin>>t;
		for(int i=1;i<=t;i++){
			solve(i);
		}
		
	}