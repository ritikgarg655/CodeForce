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
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))


void solve(){
	
int n,m,x,y,i;
cin>>n>>m>>x>>y;
cout<<x<<" "<<y<<endl;
int k=x+1;
int p=x-1;
    fo(i,1,m+1)
    {
        if(i!=y)
        cout<<x<<" "<<i<<endl;
    }
    int jj=1;
    while(k<=n)
    {
        if(jj==0){
        fo(i,1,m+1)
    {
       
        cout<<k<<" "<<i<<endl;
    }
    jj=1;
        }
        else
        {
              rfo(i,m,1)
    {
       
        cout<<k<<" "<<i<<endl;
       
    } jj=0;
        }
    k++;
    }
   
   
   
while(p>=1)
    {
        if(jj==0){
        fo(i,1,m+1)
    {
       
        cout<<p<<" "<<i<<endl;
    }jj=1;}
   
     else
        {
              rfo(i,m,1)
    {
       
        cout<<p<<" "<<i<<endl;
       
    } jj=0;
        }
    p--;
    }

}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}