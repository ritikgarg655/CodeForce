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
	int n,m;
	// n = 1;
	cin>>n>>m;
	long long int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	}
	long long ans[n][m];
	for(int i=0;i<(n+1)/2;i++){
		for(int j=0;j<(m+1)/2;j++){
			long long int temp[4];
			temp[0] = arr[i][j];
			temp[1] = arr[i][m-j-1];
			temp[2] = arr[n-i-1][j];
			temp[3] = arr[n-i-1][m-j-1];
			ll temp_m = INT_MAX;
			ll a = 0;
			for(int k = 0;k<4;k++){
				long long int sum = 0;
				for(int l = 0;l<4;l++){
					sum += abs(temp[l] - temp[k]);
				}
				if(temp_m>sum){
					temp_m = sum;
					a = k;
				}
			}
			// cout<<a<<endl;
			ans[i][j] = temp[a];
			ans[i][m-j-1] = temp[a];
			ans[n-1-i][j] = temp[a];
			ans[n-i-1][m-j-1] = temp[a];
		}
	}
	long long int ans_f = 0LL;
	for(int i=0;i<n;i++){
		for(int j = 0;j<m;j++){
			// cout<<ans[i][j]<<" ";
			ans_f+=abs(ans[i][j] - arr[i][j]);
			// cout<<ans_f<<endl;
		}
		// cout<<endl;
	}
	cout<<ans_f<<endl;
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