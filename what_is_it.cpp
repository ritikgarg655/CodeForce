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
	ll n;
	// n = 1;
	cin>>n;
	// int arr[n];
	ll ans = 0;

	for(ll i = 1;i<=(n-1)/2;i++){
		ans += abs(n/2 + i-1) * abs(n/2 + i-1);
		// cout<<n/2 + i<<" "<<1<<endl;
	}
	for(ll i = n/2;i >0;i--){
		ans += abs(i-n) * abs(i-n);
		// cout<<i<<" "<<n<<endl;
	}
	// for(int i = n;i>1;i--){
	// 	ans += abs(i-1) * abs(i-1);
	// }
	cout<<ans<<endl;
	cout<<n/2+1<<" ";
	for(int i=1;i<=n;i++){
		if(i == n/2 or i == n/2 + 1 ){
			continue;
		}
		cout<<i<<" ";
	}
	cout<<n/2;
	cout<<endl;
	cout<<n-1<<endl;
	for(int i = 1;i<=(n-1)/2;i++){
		cout<<n/2 + i<<" "<<1<<endl;
	}
	for(int i = n/2;i >0;i--){
		cout<<i<<" "<<n<<endl;
	}
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