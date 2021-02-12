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
	// ll n,k;
	// // n = 1;
	// cin>>n>>k;
	// ll a[n];
	// for(int i=0;i<n;i++){
	// 	cin>>a[i];
	// }
	// ll sum = a[0];
	// ll ans =0 ;
	// for(int i = 1 ; i < n ;i++){
	// 	if(sum*k < a[i]*100){
	// 		ans = max(ans,(ll)((a[i]*(100))-(sum*k)));
	// 		// sum = ceil(a[i]*(100.0/k));
	// 	}
	// 	sum += a[i];
	// }
	// cout<<ans<<endl;
	int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    
    long long int x = 0;
    long long int pre = p[0];
    for (int i = 1; i < n; i++) {
      x = max(x, (100*p[i] - k * pre + k - 1) / k);
      pre += p[i];
    }
    cout << x << endl;
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