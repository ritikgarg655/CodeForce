#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<long long int,long long int> pii;
typedef pair<ll,ll> pll;
typedef vector<long long int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(long long int i=a;i<b;i++)
#define repv(i,v) for(long long int i=0;i<v.size();i++)
#define reps(i,s) for(long long int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))
// index = 0
long long int dfs(long long int arr[],long long int n,long long int index,long long int post,long long int dp[][2][2]){
	if(index>=n or post>=n){
		return 0;
	}
	if(dp[index][post%2][0]!=-1){
		long long int a = dp[index][post%2][0];
		long long int b = dp[index][post%2][1];
		if(a + (post%2==0?arr[index]:-arr[index]) > b  or ((a + (post%2==0?arr[index]:-arr[index]) == b) and post%2==1)){
			// cout<<index<<" "<<post<<" "<<a + (post%2==0?arr[index]:-arr[index])<<" "<<b<<endl;
			return a + (post%2==0?arr[index]:-arr[index]);
		}
		else{
			return b;
		}
	}
	long long int a = dfs(arr,n,index+1,post+1,dp);
	long long int b = dfs(arr,n,index+1,post,dp);
	if(post%2==0){
		dp[index][0][0] = a;
		dp[index][0][1] = b;
	}
	else{
		dp[index][1][0] = a;
		dp[index][1][1] = b;
	}
	if((a + (post%2==0?arr[index]:-arr[index]) > b) or ((a + (post%2==0?arr[index]:-arr[index]) == b) and post%2==1)){
		// cout<<index<<" "<<post<<" "<<a + (post%2==0?arr[index]:-arr[index])<<" "<<b<<endl;
		return a + (post%2==0?arr[index]:-arr[index]);
	}
	else{
		return b;
	}
}

void solve(){
	long long int n,q;
	// n = 1;
	cin>>n>>q;
	long long int arr[n];
	long long int dp[n][2][2]; // n elemt 2 for even odd 
	for(long long int i=0;i<n;i++){
		cin>>arr[i];
		dp[i][1][0] = -1;
		dp[i][0][0] = -1;
		dp[i][1][1] = -1;
		dp[i][0][1] = -1;
	}
	cout<<dfs(arr,n,0,0,dp)<<endl;

}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	long long int t;
	cin>>t;
	while(t--){
		solve();
	}
}