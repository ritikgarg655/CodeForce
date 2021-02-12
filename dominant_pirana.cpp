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
	int n;
	cin>>n;
	int arr[n];
	int a;
	bool done = false;
	cin>>arr[0];
	a= arr[0];
	int maxe = arr[0];
	int index = 1;
	for(int i=1;i<n;i++){
		cin>>arr[i];
		if(arr[i]!=a){
			done = true;
		}
		if(arr[i]>maxe){
			maxe = arr[i];
			index = i+1;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i] == maxe){
			if(i>0){
				if(arr[i-1]!=maxe){
					index = i+1;
				}
			}
			if(i<n-1){
				if(arr[i+1]!=maxe){
					index = i+1;
				}
			}
		}
	}
	if(done ){
		cout<<index<<endl;
	}
	else{
		cout<<-1<<endl;
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