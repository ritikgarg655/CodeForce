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
	long long int n;
	// n = 1;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long int max_pow = sqrt(arr[n-1])+1;
	for(long long int i=1;i<sqrt(arr[n-1])+1;i++){
		if(arr[n-1]<=pow(i,n-1)){
			max_pow = i;
			break;
		}
	}
	long long int cost1 = 0LL,cost2 = 0LL;
	for(int i=0;i<n;i++){
		cost1 += abs(arr[i]-pow(max_pow,i));
		cost2 += abs(arr[i]-pow(max_pow-1,i));
	}
	cout<<min(cost1,cost2)<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}