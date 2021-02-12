// #include<bits/stdc++.h>
// using namespace std;

// // template 
// typedef long long ll;
// typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ll> vl;
// typedef vector<vl> vvl;
// typedef vector<pii> vii;

// #define pb push_back
// #define mp make_pair
// #define f first
// #define s second
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define repv(i,v) for(int i=0;i<v.size();i++)
// #define reps(i,s) for(int i=0;i<s.length();i++)
// #define allv(v) v.begin(),v.end()
// #define alla(arr,sz) arr,arr+sz
// #define rev(v) reverse(allv(v))
// #define reva(a) reverse(alla(a))


// void solve(){
// 	int i,j,k,q,l;
// 	int n;
// 	// n = 1;
// 	cin>>n;
// 	ll arr[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 	}
// 	sort(arr,arr+n);
// 	ll last = 2*n;
// 	// stack<int> 
// 	ll ans =0;
// 	ll rem = 0;
// 	bool done = false;
// 	for(int i=n-1;i>=0;i--){
// 		if(last == arr[i]){
// 			if(rem>0 and i+1!=arr[i]){
// 				rem--;
// 				ans++;
// 			}

// 			last--;
// 		}
// 		else{
// 			rem += (last - arr[i]);
// 			last = arr[i]-1;
// 			if(rem>0 and i+1!=arr[i]){
// 				ans++;
// 				rem--;
// 			}
// 			if(i+1==arr[i]){
// 				done = true;
// 			}
// 		}
// 	}
// 	if(done or ans == 0)
// 		ans++;
// 	cout<<ans<<endl;
// }

// int main(){
// 	ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// 	int t;
// 	// t = 1;
// 	cin>>t;
// 	while(t--){
// 		solve();
// 	}
// }
#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n;
vector<int> b;

inline bool read() {
	if(!(cin >> n))
		return false;
	b.resize(n);
	fore (i, 0, n)
		cin >> b[i];
	return true;
}

int getMax(const vector<int> &a, const vector<int> &b) {
	int uk = 0;
	fore (i, 0, sz(a)) {
		while (uk < sz(b) && b[uk] < a[i])
			uk++;
		if (uk >= sz(b))
			return i;
		uk++;
	}
	return sz(a);
}

inline void solve() {
	vector<int> nb;
	fore (i, 1, 2 * n + 1) {
		if (!binary_search(b.begin(), b.end(), i))
			nb.push_back(i);
	}
	
	int mxX = getMax(b, nb);
	int mnX = n - getMax(nb, b);
	
	cout << mxX - mnX + 1 << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	while(t--) {
	    read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}