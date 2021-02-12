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

// bool composite_num[100001];
// complexity n*log(log(n))	
void sieve_prime(int n){
	cout<<n;
	bool prime[n+1];
	rep(i,0,n+1){
		prime[i] = true;
	}
	rep(i,2,sqrt(n)+1){
		if(prime[i]){
			cout<<i<<endl;
			rep(j,i*i,n+1){
				prime[j] = false;
				j += i-1;
			}
		}
	}
	rep(i,0,n+1){
		if(prime[i]){
			cout<<i<<" ";
		}
	}
}

void solve(){
	int n;
	cin>>n;
	sieve_prime(n);
}

int main(){
	// ios::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}