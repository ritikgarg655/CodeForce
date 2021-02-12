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
// #define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))


void solve(){
	int i,j,k,q,l;
	int n,d,m;
	// n = 1;
	cin>>n>>d>>m;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// priority_queue<int> p;
	priority_queue<int> pm;
	for(int i=0;i<n;i++){
		// p.push(arr[i]);
		pm.push(arr[i]);
	}
	int big_m = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>m){
			big_m++;
		}
	}
	long long int ans = 0LL;
	int tot_ind = min(big_m,n/(d+1) + (n%(d+1)!=0?1:0));
	cout<<(n-big_m)/d<<endl;
	bool neg = false;
	// int a;+
	cout<<tot_ind;
	if((n-big_m)/d  >= (tot_ind-1) and tot_ind>0 and n-big_m>0){
		cout<<1;
		tot_ind--;
		neg = true;
	}
	int a = max(0,n - (tot_ind*(d+1)));
	cout<<a;
	tot_ind += a;
	// if(neg){
	// 	tot_ind++;
	// }
	for (int i = 0; i < tot_ind; ++i)
	{
		ans+=pm.top();
		pm.pop();
	}
	// ans += last;
	cout<<ans<<endl;
}

int main(){
	//ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}