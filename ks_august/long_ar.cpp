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
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int prev_diff = 0;
	int max_length = 0;
	int temp_length =0 ;
	for(int i=1;i<n;i++){
		if(arr[i]-arr[i-1]!=prev_diff){
			if(max_length<temp_length+1){
				max_length = temp_length+1;
			}
			temp_length = 1;
			prev_diff = arr[i]-arr[i-1];
		}
		else{
			temp_length++;
		}
		// cout<<temp_length<<endl;
	}
	if(temp_length+1>max_length){
		max_length = temp_length+1;
	}
	cout<<max_length<<endl;
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