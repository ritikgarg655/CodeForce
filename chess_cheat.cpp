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
	// int i,j,k,q,l;
	int n,k;
	// n = 1;
	cin>>n>>k;
	string s;
	cin>>s;
	priority_queue<int,vector<int>,greater<int>> pq; // inc in wt with less length
	bool prev = false; // means previous is L
	int len = 0; // len of cont containing w
	// bool prev_p = false; // before cont w is L is present
	int prev_len = -1;
	for(int i=0;i<s.length();i++){
		if(s[i]=='W'){
			if(len>0){
				if(prev){
					pq.push(len);
				}
				else{
					prev_len =(len);
				}
			}
			prev = true;
			len = 0;
		}
		else{
			len++;
		}
	}
	int cur_len = 0;
	long long int ans = 0;
	int temp_prev = false;
	bool w_pres = false;
	for(int i=0;i<n;i++){
		if(s[i]=='W'){
			w_pres = true;
			if(temp_prev){
				ans+=2;
			}
			else{
				ans+=1;
			}
			temp_prev = true;
		}
		else{
			temp_prev = false;
		}
	}
	// cout<<ans<<endl;
	// cout<<prev_len;
	while(cur_len<k){
		// cout<<cur_len<<" "<<ans;
		if(!pq.empty()){
			// cout<<"A";
			int t = pq.top();
			pq.pop();
			if(cur_len+t<=k){
				ans+=2*t+1;
				cur_len+=t;
			}
			else{
				ans+= 2*(k-cur_len);
				cur_len = k;
			}
		}
		else if(len>0 and w_pres){
			// cout<<"D";
			if(1){
				if(cur_len+len<=k){
					ans+=2*len;
					cur_len+=len;
				}
				else{
					ans+= 2*(k-cur_len);
					cur_len = k;
				}
			}
			len = 0;
		}
		else if (prev_len>0 and w_pres){
			// cout<<"B";
			if(cur_len+prev_len<=k){
				// cout<<2*prev_len;
				ans+=2*prev_len;
				cur_len+=prev_len;
			}
			else{
				// cout<<"da";
				ans+= 2*(k-cur_len);
				cur_len = k;
			}
			prev_len = false;
		}	
		else if(len>0){
			// cout<<"C";
			{
				if(cur_len+len<=k){
					ans+=2*len-1;
					cur_len+=len;
				}
				else{
					ans+= 2*(k-cur_len)-1;
					cur_len = k;
				}

			}
			len = 0;
		}
		else{
			break;
		}
	}
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