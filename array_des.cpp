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
	// n = 1;
	cin>>n;
	int arr[2*n];
	map<int,vector<int>> mp1;
	for(int i=0;i<2*n;i++){
		cin>>arr[i];
		// mp[arr[i]].push_back(i);
	}
	sort(arr,arr+2*n);
	for(int i=0;i<2*n;i++){
		// cin>>arr[i];
		mp1[arr[i]].push_back(i);
	}
	bool fd = false;
	vector<pair<int,int>> ans;
	for(int i = 0;i<2*n-1;i++){
		map<int,vector<int>> mp(mp1);
		int req = arr[2*n-1];
		bool done[2*n] = {false};
		int j;
		vector<pair<int,int>> temp;
		done[i] = true;
		done[2*n-1] = true;
		temp.push_back({arr[2*n-1],arr[i]});
		for(j = 2*n-2;j>=0;j--){
			if(j == i){
				continue;
			}
			if(done[j]){
				continue;
			}
			done[j] = true;
			int q1 = req - arr[j];
			req = arr[j];
			temp.push_back({arr[j],q1});
			if(mp.find(q1)==mp.end()){
				break;
			}
			bool q2  = false;
			while(mp[q1].size()!=0){
				if(!done[mp[q1].back()]){
					done[mp[q1].back()] = true;
					mp[q1].pop_back();
					q2 = true;
					break;
				}
				mp[q1].pop_back();
			}
			if(!q2){
				break;
			}
		}
		if(j == -1){
			fd = true;
			ans.push_back({arr[2*n-1] + arr[i],-1});
			for(int k = 0;k<temp.size();k++){
				ans.push_back(temp[k]);
			}
			break;
		}
	}
	if(fd){
		cout<<"YES"<<endl;
		cout<<ans[0].first<<endl;
		for(int i = 1 ; i < ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
	// t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}