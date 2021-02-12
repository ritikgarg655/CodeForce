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
	int n,m;
	// n = 1;
	cin>>n>>m;
	int a[n],b[m];
	int freq[m] = {0};
	ll sum = 0;
	// cout<<n<<m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		freq[min(a[i]-1,m-1)]++;
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		sum += b[i];
	}
	// cout<<"cds";
	ll ans = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=m-1;i>=0;i--){
		pq.push({b[i],i});
		// while(freq[i]>0){
		// 	if(!pq.empty()){
		// 		ans += pq.top();
		// 		pq.pop();
		// 	}
		// 	else{
		// 		ans += b[i];
		// 	}
		// 	freq[i]--;
		// }
		// cout<<ans<<" ";
	}
	for(int i=m-1;i>=0;i--){
		while(freq[i]>0){
			while(!pq.empty() and pq.top().second>i){
				pq.pop();
			}
			if(!pq.empty()){
				if(b[i]<=pq.top().first){
					ans += b[i];
				}
				else{
					ans += pq.top().first;
					pq.pop();
				}
			}
			else{
				ans += b[i];
			}
			freq[i]--;
		}
	}

	// ll t = 0;
	// while(!pq.empty()){
	// 	t+=pq.top();
	// 	pq.pop();
	// }
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