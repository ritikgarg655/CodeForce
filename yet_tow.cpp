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
	int a,b;
	cin>>a>>b;
	int ans = ((abs(b-a))/10) ;
	// cout<<((abs(b-a))/10)*10<<" "<<(b-a);
	ans+=(((((abs(b-a))/10)*10)==abs(b-a))?0:1);
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