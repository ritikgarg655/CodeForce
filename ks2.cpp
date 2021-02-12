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

bool check(ll n){
	int index =1;
	while(n>0){
		int d = n/(ll)pow(10,(int)(log(n)/log(10)));
		// cout<<(int)(log(n)/log(10))<<" ";

		n%=(ll)pow(10,(int)(log(n)/log(10)));
		if(d%2!=1 and index%2==1){
			return false;
		}
		else if(d%2!=0 and index%2==0){
			return false;
		}
		index++;
	}
	return true;
}

ll count(ll n){
	int sz = 0;
	ll temp = n;
	while(temp>0){
		temp/=10;
		sz++;
	}
	temp  = n;
	ll ans = 0;
	int index = 1;
	for(int i=sz;i>0;i--){
		int d = temp/(ll)pow(10,i-1);

		temp%=(ll)pow(10,i-1);
		if(d==0){
			if(index%2==1){
				break;
			}
			else{
				index++;
				continue;
			}
		}
		if(d==1 and index%2==1 and index!=sz){
			ans += (ll)pow(5,i-1);
			index++;
			continue;
		}
		// cout<<d;
		if(index%2==1){
			ans += (((d-1))/2)*(ll)pow(5,i-1);
			if(i!=1){
				ans += (ll)pow(5,i-1);
			}
			if(d%2==0 and i!=1){
				ans += (ll)pow(5,i-1);
				break;
			}
		}
		else{
			ans += (((d-2))/2+1)*(ll)pow(5,i-1);
			if(i!=1){
				ans += (ll)pow(5,i-1);
			}
			if(d%2==1 and i!=1){
				ans += (ll)pow(5,i-1);
				break;
			}
		}
		// cout<<ans;
		index++;
	}
	return ans;
}

void solve(){
	ll l,r;
	cin>>l>>r;
	ll ans1 = count(l);
	ll ans2 = count(r);
	ll ans = ans2-ans1;
	if(check(l-1)){
		// cout<<"q";
		ans--;
	}
	// cout<<ans1<<" "<<ans2;
	if(check(r)){
		// cout<<'q';
		ans++;
	}
	if(check(r-1)){
		// cout<<'q';
		ans++;
	}
	// cout<<ans2<<" "<<ans1<<endl;
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
}