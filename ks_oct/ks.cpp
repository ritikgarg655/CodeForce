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
// KICK
bool check_k(string s,ll in){
	string temp = "KICK";
	for(ll i=0;i<4;i++){
		if(temp[i] != s[in-3+i])
			return false;
	}
	return true;
}
bool check_s(string s,ll in){
	string temp = "START";
	for(ll i=0;i<5;i++){
		if(temp[i] != s[in-4+i])
			return false;
	}
	return true;
}

void solve(int i){
	string s;
	cin>>s;
	long long int ans = 0;
	long long int count = 0;
	for(long long int i=0;i<s.length();i++){
		// if(s[i] == 'K'){

		// }
		// else if(s[i] == 'S')
		if(i>=3 and s[i] == 'K'){
			if(check_k(s,i)){
				count++;
			}
		}
		if(i>=4 and s[i] == 'T'){
			if(check_s(s,i)){
				ans+=count;
			}
		}
	}
	cout<<"Case #"<<i<<": "<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	for(int i=1;i<=t;i++){
		solve(i);
	}
	
}