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
	vector<int> arr;
	int zero = 0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a!=0){
			// cout<<a;
			arr.push_back(a);
		}
		else
			zero++;
	}
	if(arr.size()==0){
		cout<<"NO"<<endl;
		return;
	}
	sort(arr.begin(),arr.end(),greater<int>());
	long long int sum = 0;
	bool done = true;
	bool cond = false;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
		if(sum == 0){
			if(i == arr.size()-1){
				done = false;
			}
			else{
				if(arr[i] == arr[arr.size()-1]){
					cond = true;
				}
				else{
					int a = arr[arr.size()-1];
					arr[arr.size()-1] = arr[i];
					arr[i] = a;
					sum -= arr[arr.size()-1];
					sum+=arr[i];
				}
			}
		}
	}
	if(cond){
		sort(arr.begin(),arr.end());
	}
	// cout<<zero;
	if(done){
		cout<<"YES"<<endl;
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		for(int i=0;i<zero;i++){
			cout<<0<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
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