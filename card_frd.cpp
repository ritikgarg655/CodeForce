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

int bs(vector<int> &pow2,int x,int start,int end){
	if(start>end){
		return -1;
	}
	if(start == end){
		if(x%(int)pow(2,start) == 0){
			return start;
		}
		return -1;
	}
	int mid = start + (end - start)/2;
	if( x % (int)pow(2,mid) == 0 ){
		if(x% (int)pow(2,mid+1) == 0){
			return bs(pow2,x,mid+1,end);
		}
		else{
			return mid;
		}
	}
	else{
		return bs(pow2,x,start,mid-1);
	}
}

void solve(){
	int w,h,n;
	cin>>w>>h>>n;
	vector<int> pow2;
	int i = 1;
	while(i<=10000){
		pow2.push_back(i);
		i*=2;
	}
	int q1 = bs(pow2,h,0,pow2.size()-1);
	int q2 = bs(pow2,w,0,pow2.size()-1);
	// cout<<q1<<" "<<q2<<endl;
	if((pow2[q1] )*(pow2[q2]) >=n){
		cout<<"YES"<<endl;
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