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
	int k;
	cin>>k;
	string s;
	cin>>s;
	int mp[27] = {0};
	for(int i=0;i<s.length();i++){
		mp[s[i]-'a'] = i+1;
	}
	mp[s[0]-'a'] = 1;
	int ans = 0;
	vector<int> v;
	for(int i=0;i<26;i++){
		if(mp[i]!=0){
			ans++;
			v.push_back(mp[i]);
		}
	}
	if(ans>=k){
		cout<<"YES"<<endl;
		sort(v.begin(),v.end());
		int end = 0;
		for(int i=0;i<k-1;i++){
			int start = v[i]-1;
			int end = v[i+1]-1;
			for(int j=start;j<end;j++){
				cout<<s[j];
			}
			cout<<endl;
		}
		for(int i=v[k-1]-1;i<s.length();i++){
			cout<<s[i];
		}
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
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}