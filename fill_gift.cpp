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
	int i,j,k,q,l;
	int n;cin>>n;int c[n],o[n];
	int min_c = INT_MAX;
	int min_o = INT_MAX;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(min_c>c[i]){
			min_c = c[i];
		}
	}
	for(int i=0;i<n;i++){
		cin>>o[i];
		if(min_o>o[i]){
			min_o = o[i];
		}
	}
	// cout<<min_o<<min_c<<endl;
	for(int i=0;i<n;i++){
		c[i] -= min_c;
		o[i] -= min_o;
	}
	long long int ans = 0LL;
	for(int i=0;i<n;i++){
		ans += (c[i] + o[i] - (min(o[i],c[i])));
		// cout<<ans<<c[i]<<o[i]<<endl;
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