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
	ll n;cin>>n;
	ll a[3],b[3];
	cin>>a[0]>>a[1]>>a[2];
	cin>>b[0]>>b[1]>>b[2];
	// ll min_e = n - (min(b[2],a[0]) + min(b[0],a[1]) + min(b[1],a[2]));
	ll max_e = min(a[2],b[0]) + min(a[0],b[1]) + min(a[1],b[2]);
	// ll min_e = min(a[2],b[0])-b[0]-b[1] + min(a[0],b[1]) + min(a[1],b[2]);
	ll min_e = (a[2]-b[0]-b[1])>0?(a[2]-b[0]-b[1]):0 + (a[0]-b[0]-b[2])>0?(a[0]-b[0]-b[2]):0 + (a[1]-b[0]-b[1])>0?(a[1]-b[0]-b[1]):0;
	if((a[2]-b[0]-b[1])>0){
		min_e-=a[2]-b[0]-b[1]
	}
	cout<<min_e<<" "<<max_e;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// /cin>>t;
	while(t--){
		solve();
	}
}