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


void solve(){string s;
        int n;
        cin>>n;
        cin>>s;
        int mx=0,z=1;
        for(int i=1;i<n;++i){
            if(s[i-1]==s[i] and s[i]=='1'){
                z++;
            }
            else{
                if(z>1) mx+=(z-1);
                z=1;
            }
        }
        int mx1=0;
        z=1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i - 1] == s[i] and s[i] == '0')
            {
                z++;
            }
            else
            {
                if (z > 1)
                    mx1 += (z - 1);
                z = 1;
            }
        }
        cout<<max(mx,mx1)<<endl;
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