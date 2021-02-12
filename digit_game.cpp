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
	// int i,j,k,q,l;
	int n;
	// n = 1;
	cin>>n;
	int odd = 0,even = 0;
	int arr;cin>>arr;
	bool even_pos = false;
	while(arr>0){
		int val = arr%10;
		arr/=10;
		if(even_pos and val%2==1){
			even++;
		}
		if(!even_pos and val%2==0){
			odd++;
		}
		even_pos = !even_pos;
	}
	if(n%2==1){
		if(odd>n/2){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	else{
		if(even>=n/2){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
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