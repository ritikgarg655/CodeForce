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


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[n],ak[k];
    rep(i,0,n){
    	cin>>arr[i];
    }
    rep(i,0,k){
    	cin>>ak[i];
    	ak[i]--;
    }
    if(k!=0){
    	sort(ak,ak+k);
    	int prev = arr[ak[0]];
    	int ind = ak[0];
    	rep(i,1,k){
    		if(prev>arr[ak[i]] or (ak[i] - ind > arr[ak[i]] - arr[ind])){
    			cout<<-1<<endl;
    			return 0;
    		}
    		prev = arr[ak[i]];
    		ind = ak[i];
    	}
    }
    rep(i,0,n){
    	
    }
}