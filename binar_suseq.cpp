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

// #define pb push_back;
// #define mp make_pair;
// #define f first;
// #define s second;
// #define rep(i,a,b) for(int i=a;i<b;i++);
// #define repv(i,v) for(int i=0;i<v.size();i++);
// #define reps(i,s) for(int i=0;i<s.length();i++);
// #define allv(v) v.begin(),v.end();
// #define alla(arr,sz) arr,arr+sz;
// #define rev(v) reverse(allv(v));
// #define reva(a) reverse(alla(a));


void solve(){
	int i,j,k,q,l;
	int n;cin>>n;
	string s;cin>>s;
	// int ans[n] = {0};
	// ans[0] = 1;
	// bool one = s[0]=='0'?false:true;
	// int len/ = 1;
	long long int arr1[2] = {0,0};// which is next required
	
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(arr1[0]!=0){
				arr1[0]--;
				arr1[1]++;
			}
			else{
				arr1[1]++;
			}
		}
		else{
			if(arr1[1]!=0){
				arr1[1]--;
				arr1[0]++;
			}
			else{
				arr1[0]++;
			}
		}
	}
	cout<<arr1[0]+arr1[1]<<endl;
	int stre[arr1[0]+arr1[1]+1] = {0};
	for(int i=0;i<arr1[0]+arr1[1]+1;i++){
		stre[i] = -1;
	}
	long int seq_num = 1;
	for(int i = 0;i<n;i++){
		if(i==0 or s[i]!=s[i-1]){
			cout<<1<<" ";
			seq_num = 1;
		}
		else{
			seq_num++;
			while(stre[seq_num]+'0'==s[i]){
				seq_num++;
			}
			cout<<seq_num<<" ";
			if(s[i]=='0'){
				stre[seq_num] = 0;
			}
			else{
				stre[seq_num] = 1;
			}
		}
	}
	cout<<endl;
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