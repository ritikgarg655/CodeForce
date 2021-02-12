#include<bits/stdc++.h>
using namespace std;

// template 
// typedef long long ll;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ll> vl;
// typedef vector<vl> vvl;
// typedef vector<pii> vii;

// #define pb push_back
// #define mp make_pair
// #define f first
// #define s second
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define repv(i,v) for(int i=0;i<v.size();i++)
// #define reps(i,s) for(int i=0;i<s.length();i++)
// #define allv(v) v.begin(),v.end()
// #define alla(arr,sz) arr,arr+sz
// #define rev(v) reverse(allv(v))
// #define reva(a) reverse(alla(a))


void solve(){
	string s;cin>>s;
	int x;cin>>x;
	string ans;
	int n = s.length();
	// cout<<"cds";
	for(int i=0;i<s.length();i++){
		ans += '1';
	}
	// cout<<ans<<endl;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			if(i>=x){
				ans[i-x] = '0';
			}
			if((i+x<n)){
				ans[i+x] = '0';
			}
		}
	}
	// cout<<ans<<endl;
	bool done = true;
	for(int i=0;i<s.length();i++){
		if(s[i] == '1' and !((i>=x and ans[i-x]=='1') or ((i+x<n) and ans[i+x]=='1'))){
			done = false;
			// cout<<i;
			break;
		}
	}
	if(done){
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
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