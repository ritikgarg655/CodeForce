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
	int x1,x2,y1,y2,z1,z2;
	int temp;
	long long int ans = 0LL;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	if(z1>0 and y2>0){
		int temp = min(z1,y2);
		ans += temp*2;
		z1-=temp;
		y2-=temp;
	}	
	// if(z2>0 and y1>0){
	// 	int temp = min(z2,y1);
	// 	ans += temp*2;
	// 	z2-=temp;
	// 	y1-=temp;
	// }
	// if(z1	>0 and x2>0){
	// 	int temp = min(z1,x2);
	// 	z1 -= temp;
	// 	x2 -= temp;
	// }
	
	// if(z2>0 and x1>0){
	// 	int temp = min(z2,x1);
	// 	z2 -= temp;
	// 	x1 -= temp;
	// }
	
	// if(y1>0 and x2>0){
	// 	int temp = min(y1,x2);
	// 	y1 -= temp;
	// 	x2 -= temp;
	// }
	
	// if(x1>0 and y2>0){
	// 	int temp = min(z1,y2);
	// 	x1 -= temp;
	// 	y2 -= temp;
	// }
	temp = min(y1,y2);
	y1-=temp;
	y2-=temp;
	temp = min(z1,z2);
	z1-=temp;
	z2-=temp;
	temp = min(y1,x2);
	y1-= temp;
	x2-=temp;
	temp  = min(y1,z2);
	ans -= temp*2;
	y1-=temp;
	z2-=temp;
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