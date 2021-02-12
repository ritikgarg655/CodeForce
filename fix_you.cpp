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
	// cout<<n<<m;
	char arr[n][m];
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			// cout<<arr[i][j];
			if(i==n-1 and j!=m-1 and arr[i][j]=='D'){
				ans++;
			}
			if(j==m-1 and i!=n-1 and arr[i][j]=='R'){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
	// ios::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	// cout<<t;
	while(t--){
		solve();
	}
}