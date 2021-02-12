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
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n == 1){
		cout<<0<<endl;
		return;
	}
	int ht = 1;
	int prev = INT_MIN;
	int child = 1;
	int tc = 0;
	int ele = 0;
	for(int i=1;i<n;i++){
		if(prev>arr[i]){
			// ht++;
			tc++;
			// prev = arr[i];
		}
		if(tc == child){
			ht++;
			child = ele;
			tc = 0;
			ele = 0;
			// child++;
		}
		// cout<<tc<<" "<<child<<" "<<ele<<" "<<ht<<endl;
		prev = arr[i];
		ele++;
	}
	// tc++;
	// 	if(tc == child){
	// 		ht++;
	// 		child = ele;
	// 		tc = 0;
	// 		ele = 0;
	// 		// child++;
	// 	}
	cout<<ht<<endl;
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