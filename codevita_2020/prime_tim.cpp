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
	int d,p;
	cin>>d>>p;
	bool prime[502] = {false};
	prime[2] = true;

	// finding all prime number in upto 501;
	for(int i=3;i<502;i++){
		bool d = true;
		for(int j=2;j<sqrt(i)+1;j++){
			if(i%j == 0){
				d = false;
				break;
			}
		}
		if(d){
			prime[i] = true;
		}
	}
	int ans = 0 ;
	// iterate to each hour.
	for(int i=2;i<d/p+1;i++){
		bool w = true;
		// for preiod loop
		for(int j=0;j<p;j++){
			if(!prime[i+(j*(d/p))]){
				w = false;
				break;
			}
		}
		if(w){
			// cout<<i;
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
	while(t--){
		solve();
	}
}