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
	int n;cin>>n;float arr[n];
	long int sum = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}
	float temp[n];
	for(int i=0;i<n;i++){
		temp[i]  = arr[i];
	}
	sort(temp,temp+n);
	int ans = 0;
	int a = 5 * temp[n-1];
	while(a--){
		map<int,float> m;
		for(int i=0;i<n;i++){
			m[temp[i]]++;
		}
		for(auto it = m .begin();it!=m.end();it++){
			if(ans<(it->second/2) and (int)it->first == it->first){
				ans = (it->second) / 2;
			}
		}
		if(temp[n-1]!=0){
			temp[0]+=0.5;
		}
		temp[n-1]-=0.5;
		for(int i = 1;i<n;i++){
			if(temp[i]<temp[i-1]){
				float temp1 = temp[i];
				temp[i] = temp[i-1];
				temp[i-1] = temp1;
			}
			else{
				break;
			}
		}
		for(int i = n-1;i>0;i--){
			if(temp[i]<temp[i-1]){
				float temp1 = temp[i];
				temp[i] = temp[i-1];
				temp[i-1] = temp1;
			}
			else{
				break;
			}
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