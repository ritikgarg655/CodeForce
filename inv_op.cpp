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

int cb(int x){
	int ans = 0;

	while(x>0){
		if(x%2 == 1){
			ans++;
		}
		x/=2;
	}
	return ans;
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[m+1];
	for(int i=0;i<m+1;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i=0;i<m;i++){
		a[i] = a[i]^a[m];
		// int q = c
		if(cb(a[i])<=k){
			ans++;
		}
	}
	cout<<ans;
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