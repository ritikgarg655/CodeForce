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

int binarySearch(vector<pair<int,int>> a, int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		if (a[mid].first == x) 
		    return a[mid].second; 
		if (a[mid].first > x) 
		    return binarySearch(a, l, mid - 1, x); 
		return binarySearch(a, mid + 1, r, x); 
	} 
	return -1; 
}

void solve(){
	int i,j,k,q,l;
	int n,m;
	// n = 1;
	cin>>n>>m;
	int a[n],b[m];
	map<int,int> ma;
	vector<pair<int,int>> sort_a;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ma[a[i]] = i;
		// sort_a.push_back({a[i],i});
	}
	std::vector<pair<int,int>> sort_b;
	for(int i=0;i<m;i++){
		cin>>b[i];

		sort_b.push_back({b[i],i});
	}
	// sort(sort_a.begin(),sort_a.end());
	// sort(sort_b.begin(),sort_b.end());
	long long int ans_f = 0LL;
	int prev_pred = 0;
	int prev_find = 0;
	for(int i=0;i<m;i++){
		int pos = ma[b[i]];
		if(pos<prev_pred){
			prev_find++;
			ans_f++;
			continue;
		}
		ans_f += 2*(pos-(i))+1;
		prev_pred = pos+1;
	}
	cout<<ans_f<<endl;
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