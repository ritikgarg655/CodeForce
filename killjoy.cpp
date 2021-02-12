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

// vector<int> contest(vector<int> arr,int x){
// 	ll req = 0;x*(arr.size());
// 	sort(allv(arr));
// 	for(int i=0;i<arr.size();i++){
// 		if(arr[i]<0){
// 			req += (x + abs(arr[i]));
// 		}
// 		else{
// 			req += abs(x-arr[i]);
// 		}
// 	}
// 	vector<int> ans;
// 	int start = 0;
// 	while(1){
// 		if(start>=arr.size()){
// 			break;
// 		}
// 		int temp_req = 0;
// 		if(arr[start]<0){
// 			temp_req= (x + abs(arr[start]));
// 		}
// 		else{
// 			temp_req= abs(x-arr[start]);
// 		}
// 		req -= temp_req;
// 		if(arr[start] + req >x){
// 			req -= temp_req;
// 			arr[start] = x;
// 			// ans.push_back(arr[start]);
// 		}
// 		else if(arr[start] + req <x){
// 			ans.push_back(arr[start]+req);
// 			break;
// 		}
// 		else{
// 			break;
// 		}
// 		start++;
// 	}
// 	return ans;
// }

void solve(){
	// int i,j,k,q,l;
	int n,x;
	// n = 1;
	cin>>n>>x;
	vector<int> arr;

	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a!=x){
			arr.push_back(a);
		}
	}
	if(arr.size()==0){
		cout<<0<<endl;
		return ;
	}
	ll req = 0LL;
	int ans;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<0){
			req += (x + abs(arr[i]));
		}
		else{
			req += (x-arr[i]);
		}
	}
	if(req == 0 or arr.size()<n){
		ans= 1;
	}
	else {
		ans = 2;
	}
	cout<<ans<<endl;
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