/*#include<bits/stdc++.h>
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
	ll n;
	// n = 1;
	cin>>n;
	ll ans = 0;
	ll lt = 0;
	ll cor = 0;
	ll pt = 0;
	ll t[n+1];
	ll x[n];
	for(ll i=0;i<n;i++){
		// int t,x;
		cin>>t[i]>>x[i];
	}
	t[n] = INT_MAX;
	ll pc = 0;
	ll tpc = 0;
	int ti = 0;
	bool done = false;
	for(ll i=0;i<n;i++){
		// int t,x;
		// cin>>t>>x;
		if(t[i]<lt){
			if(t[i+1]<=lt and x[i] == tpc and i == n-1){
				// cout<<i;
				ans++;
				continue;
			}
		}
		else{
			pt = t[i];
			pc = cor;
			lt = t[i] + abs(cor-x[i]);
			cor = x[i];
			tpc = cor;
			ti++;
			if(i == n-1){
				ans++;
				continue;
			}
			done = false;
			// ans++;
		}
		if(cor>pc){
			// right
			ll lx = min(cor,pc + t[i+1] - t[i]);
			// cout<<lx;
			if(x[i]>=pc and x[i]<=lx){
				ans++;
				done = true;
				// cout<<i;
			}
			// else if(t[i+1]<=lt and x[i] == tpc){
			// 	ans++;
			// }
			pc = min(cor,lx);
		}
		else{
			// left
			ll lx = max(cor,pc -( t[i+1] - t[i]));
			// cout<<lx<<cor<<pc<<endl;
			if(x[i]<=pc and x[i]>=lx){
				done = true;
				ans++;
				// cout<<i;
			}
			// else if(t[i+1]<=lt and x[i] == tpc){
			// 	ans++;
			// }
			pc = max(cor,lx);
		}
		// cout<<pc<<endl;
	}
	// if(!done){
	// 	ans++;
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
*/
#include<bits/stdc++.h>
 
#define ll long long int
#define mod 1000000007
 
using namespace std;
 
 
void solve()
{
    ll n, x, y, i, j, k, temp, m;
    cin >> n;
    std::vector<pair<ll, ll>> v(n);
    for (auto &it : v)cin >> x >> y, it = {x, y};
 
    ll ans  = 0;
    ll target = v[0].second;
    ll position  = 0;
    ll t1 = v[0].first, t2 = 0, x1 = v[0].second, x2 = 0;
 
    for (i = 1; i < n; ++i)
    {
        t2 = v[i].first;
        x2 = v[i].second;
 
        if (t2 - t1 >= abs(target - position))
        {
            if ((x1 <= position && x1 >= target) || (x1 <= target && x1 >= position))
                ans++;
            position = target;
            target = x2;
        }
        else
        {
            ll new_position = (target > position) ? position + (t2 - t1) : position - (t2 - t1);
            if (x1 <= position && x1 >= new_position || x1 <= new_position && x1 >= position)
                ans++;
            position = new_position;
        }
 
        t1 = t2;
        x1 = x2;
    }
    if ((x1 <= position && x1 >= target) || (x1 <= target && x1 >= position))
        ans++;
    cout << ans << endl;
 
    return ;
}
 
int main()
{
    // #ifndef ONLINE_JUDGE
    //     //for getting input from file input.txt
    //     freopen("input.txt","r",stdin);
    //     //for writing output to output.txt
    //     freopen("output.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    // your code goes here
    return 0;
}