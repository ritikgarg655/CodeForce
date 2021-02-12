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
// #define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))

int sum(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}


void solve(){
	long long n;
		int s;
		cin >> n >> s;
		long long ans = 0;
		if (sum(n) <= s) {
			cout << 0 << endl;
			return ;
		}
		long long pw = 1;
		for (int i = 0; i < 18; ++i) {
			int digit = (n / pw) % 10;
			long long add = pw * ((10 - digit) % 10);
			n += add;
			ans += add;
			if (sum(n) <= s) {
				break;
			}
			pw *= 10;
		}
		cout << ans << endl;
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