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
	int i,j,k,q,l;
	int r,g,b;
	// n = 1;
	cin>>r>>g>>b;
	priority_queue<pair<int,int>> p;
	map<int,int> m_r,m_b,m_g;
	for(int i=0;i<r;i++){
		int a;cin>>a;
		p.push({a,0});
		m_r[a]++;
	}
	for(int i=0;i<g;i++){
		int a;cin>>a;
		m_g[a]++;
		p.push({a,1});
	}
	for(int i=0;i<b;i++){
		int a;cin>>a;
		m_b[a]++;
		p.push({a,2});
	}
	vector<int> r_big,g_big,b_big;
	long long ans = 0LL;
	while(!p.empty()){

		auto a = p.top();
		// cout<<a.f<<a.s<<endl;
		p.pop();
		int c_r = 0;
		int c_b = 0;
		int c_g = 0;
		int c_t =0;
		bool eq = false;
		while(!p.empty() and (p.top().f)==a.f ){
			// c_t++;
			eq=true;
			// cout<<c_t<<endl;
			if(a.s == 0){
				c_r++;
			}
			else if(a.s==1){
				c_g++;
			}
			else{
				c_b++;
			}
			a = p.top();
			p.pop();
		}
		// cout<<p.top().f<<a.f;
		if(c_b>0 and c_g>0 and c_r>0){
			int c = 0;
			c = min(c_r,c_g);
			c_r-=c;
			c_g-=c;
			int t = min(max(c_g,c_r),c_b);
			c_b -= t;
			if(c_g>c_r){
				c_g-= t;
			}
			else{
				c_r	-= t;
			}
			ans += (c+t) * a.f * a.f;
		}
		else if(c_r>0 and c_g>0){
			int c = 0;
			c = min(c_r,c_g);
			c_r-=c;
			c_g-=c;
			ans += c*a.f*a.f;
		}
		else if(c_b>0 and c_g>0){
			int c = 0;
			c = min(c_b,c_g);
			c_b-=c;
			c_g-=c;
			ans += c*a.f*a.f;
		}
		else if(c_r>0 and c_b>0){
			int c = 0;
			c = min(c_r,c_b);
			c_r-=c;
			c_b-=c;
			ans += c*a.f*a.f;
		}
		// cout<<c_g<<c_r<<c_b<<endl;
		if(c_g>0){
			while(c_g--)
			g_big.push_back(a.f);
		}
		if(c_r>0){
			while(c_r--)
			r_big.push_back(a.f);
		}
		if(c_b>0){
			while(c_b--)
			b_big.push_back(a.f);
		}
		if(a.s == 0){
			pair<int,int> big = {-1,-1};
			if(!g_big.empty()){
				big = {g_big[0],1};
			}
			if(!b_big.empty() and big.f < b_big[0]){
				big = {b_big[0],2};
				// cout<<"1s";
			}
			if(!b_big.empty() and big.f == b_big[0] and m_b[big.f]>1){
				// if(b_big.size()>1 and b_big[1]==big.f){
					// cout<<"a";
					big.s = 2;
				// }
			}	
			else  if(!r_big.empty() and big.f == r_big[0] and m_r[big.f]>1){
				// if(b_big.size()>1 and b_big[1]==big.f){
					big.s = 1;
					// cout<<"b";/
				// }
				// else if(!b_big.empty() and b_big.top()==big.f){
				// 	big.s = 2;
				// }
			}
			if(big.f!=-1){
				// m_r[a.f]--;
				ans += a.f * big.f;
				if(big.s == 1){
					m_g[g_big[0]]--;
					g_big.erase(g_big.begin());
				}
				else{
					m_b[b_big[0]]--;
					b_big.erase(b_big.begin());
				}
				// r_big.erase(r_big.begin());
			}
			else{
				r_big.push_back(a.f);
			}
		}
		else if(a.s == 1){
			pair<int,int> big = {-1,-1};
			if(!r_big.empty()){
				big = {r_big[0],1};
			}
			if(!b_big.empty() and big.f < b_big[0]){
				big = {b_big[0],2};
			}
			if(!r_big.empty() and big.f == r_big[0] and m_r[big.f]>1){
				// if(b_big.size()>1 and b_big[1]==big.f){
					big.s = 1;
					// cout<<"b";
				// }
				// else if(!b_big.empty() and b_big.top()==big.f){
				// 	big.s = 2;
				// }
			}
			else if(!b_big.empty() and big.f == b_big[0] and m_b[big.f]>1){
				// if(b_big.size()>1 and b_big[1]==big.f){
					// cout<<"a";
					big.s = 2;
				// }
			}	
			if(big.f!=-1){
				// m_g[a.f]--;
				ans += a.f * big.f;
				if(big.s == 1){
					m_r[r_big[0]]--;
					r_big.erase(r_big.begin());
				}
				else{
					m_b[b_big[0]]--;
					b_big.erase(b_big.begin());
				}
				// r_big.erase(r_big.begin());
			}
			else{
				g_big.push_back(a.f);
			}
		}
		else{
			pair<int,int> big = {-1,-1};
			if(!r_big.empty()){
				big = {r_big[0],1};
			}
			if(!g_big.empty() and big.f < g_big[0]){
				big = {g_big[0],2};
			}
			if(!g_big.empty() and big.f == g_big[0] and m_g[big.f]>1){
				// if(g_big.size()>1 and g_big[1]==big.f){
					big.s = 2;
					// cout<<"c";/
				// }
				// else if(!g_big.empty() and g_big.top()==big.f){
				// 	b

			}	
			else if(!r_big.empty() and big.f == r_big[0] and m_r[big.f]>1){
				// if(b_big.size()>1 and b_big[1]==big.f){
					big.s = 1;
					// cout<<"b";/
				// }
				// else if(!b_big.empty() and b_big.top()==big.f){
				// 	big.s = 2;
				// }
			}
			if(big.f!=-1){
				ans += a.f * big.f;
				// m_b[a.f]--;
				if(big.s == 1){
					m_r[r_big[0]]--;
					r_big.erase(r_big.begin());
				}
				else{
					m_g[g_big[0]]--;
					g_big.erase(g_big.begin());
				}
				// r_big.erase(r_big.begin());
			}
			else{
				b_big.push_back(a.f);
			}
		}
		// cout<<ans<<endl;
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin/>>t;
	while(t--){
		solve();
	}
}