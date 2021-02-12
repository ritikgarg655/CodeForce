#include <bits/stdc++.h>
#define N 123456789
#define INF INFINITY
using namespace std;
 
void solve()
{
	long long a,b,x,y,n,ans = 1e18;cin>>a>>b>>x>>y>>n;
	for(int i = 0;i<2;i++){
		long long da = min(n,(a-x));
		long long db = min(n-da, (b-y));
		ans = min(ans, (a-da)*(b-db));
		swap(a,b);
		swap(x,y);
	}
	cout<<ans<<endl;
}
	
 
int main()
{
	//to make I/O faster
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;cin>>t;
	while(t--)solve();
	//solve();
	
}
