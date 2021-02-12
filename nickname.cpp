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

// string bfs(string s,int count){
// 	string t = s;
// 	for(int i=0;i<26;i++){
// 		t += 'a'+i;
// 		if(!present(t)){
// 			return t;
// 		}
// 		t = s;
// 	}
// 	for(int i=0;i<26;i++){
// 		t += 'a'+i;
// 		if(!present(t)){
// 			return t;
// 		}
// 		t = s;
// 	}
// }

void solve(){
	// int i,j,k,q,l;
	int n;
	// n = 1;
	cin>>n;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<string> v;
	for(int i=0;i<n;i++){
		for(int j=0;j<arr[i].length();j++){
			for(int k = j;k<arr[i].length();k++){
				string s;
				for(int q = j;q<=k;q++){
					s += arr[i][q];
				}
				v.push_back(s);
			}
		}
	}
	sort(v.begin(),v.end());
	int l = 1;
	for(int i=0;i<v.size();i++){
		if(v[i].length()>l){
			if(count<)
		}
	}
	cout<<bfs("",0)<<endl;
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