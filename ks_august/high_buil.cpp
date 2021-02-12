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

void solve(int t){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int start = 1;
	int ans[n];
	cout<<"Case #"<<t+1<<": ";
	if(a>=c and b>=c and (a-c)+(b-c)+c<=n and !(a==c and b==c and c<n)){
		if((a-c)==0 and b-c==1){
			start = 2;
			for(int i=0;i<a-c;i++){
				ans[i] = 2;
				start++;
			}
			for(int i=0;i<c;i++){
				ans[i+(a-c)] = n;
			}
			for(int i = a;i<n-(b-c);i++){
				ans[i] = 1;
			}
			for(int i=0;i<b-c;i++){
				ans[n-i-1] = 2;
				start++;
			}
		}
		else if((b-c)==0){
			start = 2;
			for(int i=0;i<a-c;i++){
				ans[i] = 2;
				start++;
			}
			for(int i = a-c;i<n-(b-c);i++){
				ans[i] = 1;
			}
			for(int i=0;i<c;i++){
				ans[n-(i)-1] = n;
			}
		}
		else{
			for(int i=0;i<a-c;i++){
				ans[i] = 2;
				start++;
			}
			for(int i=0;i<c;i++){
				ans[i+(a-c)] = n;
			}
			for(int i = a;i<n-(b-c);i++){
				ans[i] = 1;
			}
			for(int i=0;i<b-c;i++){
				ans[n-i-1] = 2;
				start++;
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main(){
	int t;
	// t = 1;
	cin>>t;
	for(int i=0;i<t;i++){
		solve(i);
	}
}