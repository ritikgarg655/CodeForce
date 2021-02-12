#include<bits/stdc++.h>
using namespace std;

// template 
typedef int ll;
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
	ll l[n];
	for(int i=0;i<k;i++){
		cin>>l[i];
	}
	ll al,bl,cl,dl;
	cin>>al>>bl>>cl>>dl;
	ll h[n];
	for(int i=0;i<k;i++){
		cin>>h[i];
	}
	ll ah,bh,ch,dh;
	cin>>ah>>bh>>ch>>dh;
	if(n>k){
		for(int i=0;i<n-k;i++){
			l[i+k] = ((al * l[i+k-2] + bl*l[i+k-1] + cl)%dl) + 1;
			h[i+k] = ((ah * h[i+k-2] + bh*h[i+k-1] + ch)%dh) + 1;
		}
	}
	ll ans = 1;
	priority_queue<pair<ll,ll>> pq;
	ll prev_peri = (2*w + 2*h[0]);
	ans = prev_peri;
	pq.push({l[0]+w,h[0]});
	// cout<<prev_peri<<endl;
	for(int i=1;i<n;i++){
		ll overlap_c = 0;
		ll max_h = 0;
		ll ending = 0;
		vector<pair<ll,ll>> v;
		while(!pq.empty() and count<21){
			if(pq.top().first > ending){
					ending = pq.top().first;
				}
			if(pq.top().first >= l[i] ){
				
				max_h = max(max_h,pq.top().second);
				v.push_back(pq.top());
				pq.pop();
			}
			else{
				break;
			}
			overlap_c++;
		}
		// cout<<overlap_c;
		for (int i = 0; i < v.size(); ++i)
		{
			pq.push(v[i]);
		}
		// cout<<ending;
		if(overlap_c==0){
			priority_queue<pair<ll,ll>> q;
			pq = q;
			ending = l[i];
		}
		prev_peri += ((l[i]+w - ending)*2 );
		if(max_h<h[i]){
			prev_peri += (2*(h[i]-max_h));
		}
		pq.push({l[i]+w,h[i]});
		ans = ans*(prev_peri)%1000000007;
		// cout<<ending<<" "<<l[i]+w<<""<<prev_peri<<endl;
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