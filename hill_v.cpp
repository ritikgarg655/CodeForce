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
	int ans = 0;
	bool pres = false;
	bool last  = false;
	bool pres1 = false;
	for(int i =1;i<n-1;i++){
		if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
			ans++;
			if(last and (i==n-2 or !(arr[i+2] <arr[i+1]))){
				pres = true;
			}
			last = true;
		}
		else if(arr[i]<arr[i-1] and arr[i]<arr[i+1]){
			if(last and (i==n-2 or !(arr[i+2] >arr[i+1]))){
				pres = true;
			}
			ans++;
			last = true;
		}
		else{
			last = false;
		}
		// cout<<ans;
	}
	for(int i=4;i<n;i++){
		if(arr[i-4]>arr[i-3] and arr[i-3]<arr[i-2] and arr[i-2]>arr[i-1] and arr[i-1]<arr[i] and arr[i-3] <= arr[i-1]){
			pres1 = true;
		}
		if(arr[i-4]<arr[i-3] and arr[i-3]>arr[i-2] and arr[i-2]<arr[i-1] and arr[i-1]>arr[i] and arr[i-3] >= arr[i-1]){
			pres1 = true;
		}
	}
	if(pres1){
		// cout<<"cvsd";
		ans-=2;
	}
	else if(pres){
		ans -= 1;
	}
	// else{
		ans -= 1;
	// }
	cout<<max(0,ans)<<endl;
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