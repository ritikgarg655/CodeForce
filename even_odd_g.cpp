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
	int n;
	// n = 1;
	cin>>n;
	vector<ll> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.rbegin(), v.rend());
	  ll ans = 0;
	  for (int i = 0; i < n; i++) {
	    if (i % 2 == 0) {
	      if (v[i] % 2 == 0) {
	        ans += v[i];
	      }
	    } else {
	      if (v[i] % 2 == 1) {
	        ans -= v[i];
	      }
	    }
	  }
	  if (ans == 0) {
	    cout << "Tie\n";
	  } else if (ans > 0) {
	    cout << "Alice\n";
	  } else {
	    cout << "Bob\n";
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