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
	string s;
	cin>>s;
	int prev = 0;
	priority_queue<int> p;
	for(int i=0;i<s.length();i++){
		// cout<<s[i];
		if(s[i]=='1'){
			prev++;
		}
		else if(s[i]=='0' and i!=0 and s[i-1]!='0'){
			p.push(prev);
			// cout<<prev;
			prev = 0;
		}
	}
	// cout<<prev;
	p.push(prev);
	long long int ans = 0LL;
	bool start = true;
	while(!p.empty()){
		if(start){
			ans += p.top();
			p.pop();
		}
		else{
			p.pop();
		}
		start = !start;
	}
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