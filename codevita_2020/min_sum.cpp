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
	int n,k;
	// n = 1;
	cin>>n>>k;
	priority_queue<int> p;
	long long int sum =0LL;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		sum += a;
		p.push(a);
	}

	for(int i=0;i<k;i++){
		int a = p.top();
		p.pop();
		sum -= (a - (a/2));
		p.push(a/2);
		// cout<<sum<<endl;
	}
	cout<<sum;
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