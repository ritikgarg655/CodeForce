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
    int n,ma,k;
    cin>>n>>ma>>k;
    int arr[n][ma];
    rep(i,0,n){
    	rep(j,0,ma){
    		cin>>arr[i][j];
    	}
    	sort(arr[i],arr[i]+ma);
    }
    ll ans = 0LL;
    rep(i,0,n){
    	bool done[ma] = {false};
    	vector<int> m[71][71];
    	rep(j,0,ma){
    		m[arr[i][j]%k][arr[i][j]].push_back(j); // req,val
    	}
    	for(int j=ma-1;j>=0;j--){
    		int req = k-(arr[i][j]%k);
    		if(req==k){
    			done[j] = true;
    			continue;
    		}
    		for(int k=70;k>=0;k--){
    			bool d = false;
    			if(m[req][k].size()!=0){
    				for(int q=0;q<m[req][k].size();q++){
    					if(m[req][k][q]!=j and !done[m[req][k][q]]){
    						done[j] = true;
    						done[m[req][k][q]] = true;
    						d = true;

    						break;
    					}
    				}
    			}
    			if(d){
    				break;
    			}
    		}


    		// cout<<m[k-(arr[i][j]%k)][0].size();
    		// if(m[k-(arr[i][j]%k)][0].size()!=0){
    		// 	if(m[k-(arr[i][j]%k)][0].top().second == j and m[k-(arr[i][j]%k)][0].size()==1){
    		// 		continue;
    		// 	}
    		// 	auto temp = m[k-(arr[i][j]%k)][0].top();
    		// 	pair<int,int> prev ;
    		// 	bool prp = false;
    		// 	m[k-(arr[i][j]%k)][0].pop();
    		// 	// if0(
    		// 	// 	m[k-(arr[i][j]%k)].top().second == j){
    		// 	// 	temp = m[k-(arr[i][j]%k)].top();
    		// 	// }
    		// 	bool pres = true;
    		// 	// // while(!done[temp.second] or temp.second == j){
    		// 	// // 	if(temp.second == j){
    		// 	// // 		prev = temp;
    		// 	// // 		prp = true;
    		// 	// // 	}
    		// 	// // 	if(m[k-(arr[i][j]%k)][0].size()==0){
    		// 	// // 		pres = false;
    		// 	// // 	}
    		// 	// // 	temp = m[k-(arr[i][j]%k)][0].top();
    		// 	// // 	m[k-(arr[i][j]%k)][0].pop();
    		// 	// // }
    		// 	if(!pres){
    		// 		continue;
    		// 	}
    		// 	if(prp){
    		// 		m[k-(arr[i][j]%k)][0].push(prev);
    		// 	}
    		// 	done[temp.second] = true;
    		// 	done[j] = true;
    		// }
    	}
    		rep(j,0,ma){
    			if(done[j]){
    			    			ans+=arr[i][j];
    			    			cout<<j<<i<<endl;
    			    		}
    		}
    		cout<<i;
    }
    cout<<ans<<endl;
}