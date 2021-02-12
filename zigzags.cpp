#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repv(i,v) for(ll i=0;i<v.size();i++)
#define reps(i,s) for(ll i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))


void solve(){
	ll i,j,k,q,l;
	ll n;
	// n = 1;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<ll> v[n+2];
	for(ll i=0;i<n;i++){
		v[arr[i]].push_back(i);
	}
	for(ll i=0;i<n;i++){
		sort(allv(v[i]));
	}
	ll ans = 0;
	ll prev_count[n+2] = {0};
	// prev_count[arr[0]]++;
	for(ll i=1;i<n-2;i++){ // for i element in arr
		
		prev_count[arr[i-1]]++;
		if(v[arr[i]].size()<2){
			continue;
		}
		ll prev = 0;
		ll tot_comb = 0;
		ll temp = 0;
		for(ll k=i+1;k<n;k++){
			if(v[arr[k]].size()<2){
				continue;
			}
			if(arr[k] == arr[i]){
				ans+=temp;
			}
			ll l;
			temp += prev_count[arr[k]];
			
		}
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	ll t;
	// t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}