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
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	vector<pair<ll,pair<ll,pair<ll,ll>>>> v;
	// bool prev = false;
	for(ll i=1;i<n;i++){
		if(arr[i-1]<0 and arr[i]<0){
			v.push_back({arr[i-1]*arr[i],{1,{i-1,i}}});
			i++;
			// cout<<arr[i-1]*arr[i]<<endl<<"cds";
			// prev = true;
		}
		else{
			if(arr[i-1]*arr[i] != max(arr[i-1],arr[i]))
			v.push_back({arr[i-1]*arr[i],{1,{i-1,i}}});
			v.push_back({arr[i],{0,{i,-1}}});
			v.push_back({arr[i-1],{0,{i-1,-1}}});
			i++;
		}
	}
	if(n%2==1){
		v.push_back({arr[n-1],{0,{n-1,-1}}});
	}
	bool incd[n] = {false};
	sort(v.begin(),v.end());
	long long int ans = 1LL;
	ll req = 5; 
	ll v_index = (ll)v.size()-1;
	while(req>0){
		// if(v_index==)
		auto a = v[v_index];
		// cout<<a.first<<endl;
		if(a.second.first==1){
				incd[a.second.second.first] = true;
				incd[a.second.second.second] = true;
			if(req<2){
				if(v_index==0){
					break;
				}		
				v_index--;
				continue;
			}
			req-=2;
			ans*=a.first;
		}
		else if(a.first>=0){
			if(incd[a.second.second.first]){
				// cout<<a.first<<a.second.second.first<<endl;
				if(v_index==0){
					break;
				}
				v_index--;
				continue;
			}
			ans *= a.first;
			req--;
		}
		if(v_index==0){
			break;
		}
		v_index--;
	}
	if(req>0 and ans!=0){
		// cout<<"edw";
		ans = -1;
		vector<int> q;
		for(int i=0;i<n;i++){
			q.push_back(abs(arr[i]));
		}
		sort(q.begin(),q.end());
		for(int i=0;i<5;i++){
			ans*=q[i];
		}
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