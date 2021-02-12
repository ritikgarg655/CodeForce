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
	string s,t;
	getline(cin,t);
	cin>>s;
	// cout<<t<<" "<<s;
	map<char,int> m;
	for(long unsigned int i=0;i<s.length();i++){
		m[s[i]] = (int)i;
	}
	int ans = 0;
	for(long unsigned int i=0;i<t.length();i++){
		vector<int> v;
		auto it = m.find(t[i]);
		if(it!=m.end()){
			long unsigned int temp_i = i;
			v.push_back(it->second);
			while(1){
				temp_i++;
				if(temp_i<t.length()){
					auto it1 = m.find(t[temp_i]);
					if(it1!=m.end() and ((it1->second) > (it->second))){
						v.push_back(it1->second);
						it = it1;
					}
					else{
						temp_i--;
						break;
					}
				}
				else{
					temp_i--;
					break;
				}
			}
			int prev = 0;
			bool prev_taken = false;
			for(long unsigned int j=0;j<v.size();j++){
				if(j==0){
					ans += v[j];
					if(v[j]!=0){
						prev_taken = true;
						ans+=2;
					}
					prev = v[j];
				}
				else{
					if(v[j]!=prev+1 or prev_taken){
						ans+=2;
						prev_taken = true;
					}
					ans += v[j] - v[j-1]-1;
					prev = v[j];
				}
			}
			ans++;
			// cout<<s.length()-1-v[v.size()-1]<<endl;
			ans += (s.length() -1 - (v[v.size()-1]));
			i = temp_i;
			// cout<<i<<" "<<ans<<endl;
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin>>ts;
	while(t--){
		solve();
	}
}