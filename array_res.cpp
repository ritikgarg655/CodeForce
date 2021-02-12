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
	int n,x,y;
	cin>>n>>x>>y;
	int diff ;
	cout<<min(x,y)<<" "<<max(x,y)<<" ";
	if(n==2){
		cout<<endl;
		return;
	}
	int mid_Acc;
	// int diff;//
	for(int i=n-1;i>0;i--){
		if(abs(x-y)%i==0){
			diff = (abs(x-y))/i;
		mid_Acc = i-1;
		break;
		}
	}
	for(int i=0;i<mid_Acc;i++){
		cout<<min(x,y)+diff*(i+1)<<" ";
	}
	if(n>mid_Acc+2){
		int rem = n-mid_Acc-2;
		int prev = 0;
		int next = 0;
		for(int i=0;i<rem;i++){
			if(min(x,y)-((prev+1)*diff)>0){
				prev++;
				cout<<min(x,y)-((prev)*diff)<<" ";
			}
			else{
				next++;
				cout<<max(x,y)+(next*diff)<<" ";
			}
		}
	}
	cout<<endl;
	// if((abs(x-y))%(n-1)==0){
	// 	diff = (abs(x-y)/(n-1));
	// 	cout<<min(x,y)<<" ";
	// 	for(int i=1;i<n-1;i++){
	// 		cout<<min(x,y)+diff*i<< " ";
	// 	}
	// 	cout<<max(x,y)<<endl;
	// }
	// else{
	// 	// diff = 0;
	// 	diff = (abs(x-y))/(n-2);
	// 	cout<<min(x,y)<<" ";
	// 	for(int i=1;i<n-2;i++){
	// 		cout<<min(x,y)+diff*i<< " ";
	// 	}
	// 	if(min(x,y)-diff>0){
	// 		cout<<min(x,y)-diff<<" ";
	// 	}
	// 	else{
	// 		cout<<max(x,y)+diff<<" ";
	// 	}
	// 	cout<<max(x,y)<<endl;
	// }

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