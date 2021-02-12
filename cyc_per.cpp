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
long  int fact(unsigned int n) 
{ 
	static long int dp[1000001] = {0};
    long int res = 1, i; 
    if(dp[n]!=0){
    	return dp[n];
    }
    for (i = 2; i <= n; i++){ 
        res = (res*i) % 1000000007;
        dp[i] = res;
    }

    return res; 
} 

void solve(){
	// int i,j,k,q,l;
	long int n;
	// n = 1;
	cin>>n;
	long long  int ans = 0LL;
	for(long int i = n;i>=3;i--){

	}
	cout<<n*n% 1000000007<<endl;
}

int main(){
	// ios::sync_with_stdio(0);
 //    cin.tie(0);
 //    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}