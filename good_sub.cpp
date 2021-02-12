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
	string s;
	cin>>s;
	long int ans = 0,ans_p = 0;
	bool prev_zero_detec = false;
	int prefix_sum[n] = {0};
	int prefix = 0;
	int temp_prefix_s = 0;
	int temp_prefix_s_i = 0;
	
	for(int i=0;i<n;i++){
		prefix += s[i]-'0';
		// prefix_sum
		if(s[i]=='0'){
			prev_zero_detec = true;
		}
		if(prefix==i){
			ans++;
			temp_prefix_s = 0;
			temp_prefix_s_i = -1;
		}
		else{
			
		}
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