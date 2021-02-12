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
	int n;
	// n = 1;
	cin>>n;
	// int arr[n];
	int c2 = 0;
	int c1 = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a == 2){
			c2++;
		}
		else{
			c1++;
		}
	}
	bool ans = true;
	if(c1%2==1){
		ans = false;
	}
	else if(c2%2==1){
		if(c1<2){
			ans = false;
		}
	}
	if(ans){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
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