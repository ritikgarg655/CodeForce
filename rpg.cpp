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
	int p,f,cntx,cntw,x,w;
	cin>>p>>f>>cntx>>cntw>>x>>w;
	// for x;
	long long int ans = 0LL;
	int curr = 0 ;
	curr = p/(min(x,w));
	if(x>w){
		curr = min(cntw,curr);
	}
	else{
		curr = min(cntx,curr);
	}
	int rem = max(0,(p-(curr)*min(x,w))/max(x,w));
	if(x<w){
		rem = min(cntw,rem);
	}
	else{
		rem = min(cntx,rem);
	}
	// cout<<rem;
	ans = curr + rem;
	int ans_min = curr;
	int ans_max = 0;
	while(curr>0){
		curr--;
		int temp_rem = max(0,(p-(curr*min(x,w)))/max(x,w))-rem;
		rem += temp_rem;
		// cout<<temp_rem<<endl;
		// cout<<rem<<rem*max(x,w)<<endl;
		if((rem * max(x,w)) + (curr*min(x,w))>p){
			// cout<<"fr";
			break;
		}
		if(x>w and (curr>cntx or rem>cntw)){
			// cout<<"vt";
			break;
		}
		else if((rem>cntx or curr>cntw)){
			// cout<<"cds";
			break;
		}	
		if(ans>=rem+curr){
			ans  = curr+rem;
			ans_max = rem;
			ans_min = curr;
		}
	}
	// cout<<ans<<" "<<ans_min<<ans_max<<endl;
	if(x>w){
		cntx -= ans_max;
		cntw -= ans_min;
	}
	else{
		cntx -= ans_min;
		cntw -= ans_max;
	}
	curr = f/(min(x,w));
	if(x>w){
		curr = min(cntw,curr);
	}
	else{
		curr = min(cntx,curr);
	}
	rem = max(0,(f-(curr*min(x,w)))/max(x,w));
	// cout<<rem;
	if(x<w){
		rem = min(cntw,rem);
	}
	else{
		rem = min(cntx,rem);
	}
	// int rem = 0;
	// int ans = curr;
	ans += curr + rem;
	ans_min = curr;
	ans_max = 0;
	// cout<<curr<<rem;
	while(curr>0){
		curr--;
		int temp_rem = max(0,(p-(curr*min(x,w)))/max(x,w))-rem;
		rem += temp_rem;
		// cout<<temp_rem;
		if(rem * max(x,w) + (curr*min(x,w))>p){
			break;
		}
		if(x>w and (curr>cntx or rem>cntw)){
			break;
		}
		else if((rem>cntx or curr>cntw)){
			break;
		}	
		if(temp_rem>1){
			ans += temp_rem-1;
			ans_max = rem;
			ans_min = curr;
		}
	}
	// cout<<curr<<ans_min<<ans_max<<endl;
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