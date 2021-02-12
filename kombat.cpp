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

int dp[200002][2];

int dfs(int arr[],int index,bool chance,int n){
	if(index>n){
		return INT_MAX;
	}
	if(index==n){
		return 0;
	}
	if(dp[index][chance==true?1:0]!=-1){
		return dp[index][chance==true?1:0];
	}
	// chance = true means me
	int ans1 = INT_MAX,ans2 = INT_MAX,ans3 = INT_MAX,ans4 = INT_MAX;
	if(chance){	
		// I chose only one 
		ans1 = dfs(arr,index+1,!chance,n);
		// I chose both 
		ans2 = dfs(arr,index+2,!chance,n);
	}
	else{
		// friend chose only one
		ans3 = dfs(arr,index+1,!chance,n);
		// friend chose only one
		ans4 = dfs(arr,index+2,!chance,n);
		if(index<n and arr[index]==1){
			if(ans3!=INT_MAX)
			ans3++;
		if(ans4!=INT_MAX)
			ans4++;
		}
		if(index+1<n and arr[index+1]==1 and ans4!=INT_MAX){
			ans4++;
		}
	}
	dp[index][chance==true?1:0] = min(ans1,min(ans2,min(ans3,ans4)));
	return min(ans1,min(ans2,min(ans3,ans4)));
}

void solve(){

	int i,j,k,q,l;
	int n;
	// n = 1;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		dp[i][0] = -1;
		dp[i][1] = -1;
	}
	
	cout<<dfs(arr,0,false,n)<<endl;
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