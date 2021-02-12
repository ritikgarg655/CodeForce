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
	int n,k,w;
	cin>>n>>k>>w;
	int l[n];
	for(int i=0;i<k;i++){
		cin>>l[i];
	}
	long int al,bl,cl,dl;
	cin>>al>>bl>>cl>>dl;
	int h[n];
	for(int i=0;i<k;i++){
		cin>>h[i];
	}
	long int ah,bh,ch,dh;
	cin>>ah>>bh>>ch>>dh;
	if(n>k){
		for(int i=0;i<n-k;i++){
			l[i+k] = ((al * l[i+k-2] + bl*l[i+k-1] + cl)%dl) + 1;
			h[i+k] = ((ah * h[i+k-2] + bh*h[i+k-1] + ch)%dh) + 1;
		}
	}
	ll start_x = 0;
	int max_height = 0;
	ll max_x = 0;
	long long int prev_sum = 0LL;
	ll ans = 1LL;
	int prev_Add = 0;
	ll prev_peri = 0;
	int end_prev_max = 0;
	int min_bet = h[0];
	map<int,int> m_end;
	// for(int i=0;i<n;i++){
	// 	cout<<l[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<n;i++){
	// 	cout<<h[i]<<" ";
	// }
	// cout<<endl;
	for(int i=0; i<n;i++){
		if(max_x<l[i]){
			prev_sum += prev_peri;
			start_x = l[i];
			max_height =0;
			prev_Add = 0;
			min_bet = h[i];
		}
		if(min_bet>h[i]){
			min_bet = h[i];
		}
		max_x = (l[i]+w);
		int prev_max_h = max_height;
		max_height = max(max_height,h[i]);
		// if(max_height == h[i]){
		// 	min_bet = max_height;
		// }
		if(h[i]==max_height and i!=0 and h[i-1] != prev_max_h and end_prev_max<l[i] and max_height>min_bet){
			if(m_end.find(l[i])!=m_end.end() and m_end[l[i]]<l[i]){
				
			}
			else{
			prev_Add +=  (prev_max_h- min_bet)*2;
			}// min_bet =
		}
		if(h[i]!=max_height and i!=0 and h[i-1]!=prev_max_h and min_bet<h[i] and end_prev_max<l[i]){
			if(m_end.find(l[i])!=m_end.end() and m_end[l[i]]<l[i]){

			}
			else{
				prev_Add += (h[i]- min_bet)*2;
				// cout<<i<<endl;
				min_bet = h[i];
			}
		}
		if(h[i]==max_height){
			min_bet  = max_height;
			end_prev_max = max_x;
		}
		if(m_end.find(max_x)==m_end.end()){
			m_end[max_x] = h[i];
		}
		else if(m_end[max_x]<h[i]){
			m_end[max_x] = h[i];
		}
		ans = (ans * ((ll)((2*(max_x-start_x) + prev_Add + (2*max_height) + prev_sum))%1000000007))%1000000007;
		prev_peri = (ll)(2*(max_x-start_x) + prev_Add + (2*max_height) + prev_sum);
		// prev_pe = (ll)((2*(max_x-start_x)+temp_pe + (2*max_height) + prev_sum));
		cout<<l[i]<<" "<<h[i]<<" "<<prev_peri<<" "<<endl;
		// cout<<start_x<<" "<<max_x<<" "<<max_height<<" "<<ans<<" "<<(2*(max_x-start_x) + prev_Add + (2*max_height) + prev_sum)<<" "<<prev_Add<<endl;
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
	for(int i=0;i<t;i++){
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
}