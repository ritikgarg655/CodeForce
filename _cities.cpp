#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>//memset()
#include<algorithm>
#include<sstream>
#include<stack>
#include<bitset>
#include<queue>
#include<cmath>
#include<set>
#include<iomanip>
#define ll long long
#define PI 3.14159265358979323846
#define IO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define rep(i,start,end) for(int i=start;i<end;i++)
#define per(i,start,end) for (int i=end-1;i>=start;i--)
using namespace std;
    
const ll mod=1e9+7;
const ll inf=1e18+5;
const ll SZ=2e5+5;
    
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) { return a*b/gcd(a,b);}
ll leastbit(ll a) { return a&(-a);}
ll C(int a,int b) { ll res=1;rep(i,0,b)res=res*(a-i)/(i+1);return res;}
ll powmod(ll a,ll  b) { if(b==0)return 1;ll cnt=powmod(a,b/2);(cnt*=cnt) %=mod;if(b&1){(cnt*=a) %= mod;}return cnt;}
    
ll n,m,k,d[300005],cnt=0,done[300005];
vector<pair<ll,pair<ll,ll>>>adj[300005];
map<ll,ll>mp;
set<ll>st;
//map<pair<int,pair<int,int>,ll>mp;
void dijkstra(){
    for(int i=0;i<300005;i++)d[i]=inf;
    //cout<<d[5]<<endl;
    d[1]=0;
    priority_queue<pair<ll,pair<ll,ll>>>q;
    q.push({0ll,{0ll,1ll}});
    
    while(!q.empty()) {
        ll t = -q.top().second.first; 
        ll y = -q.top().first; 
        ll x = q.top().second.second; 
        
        q.pop();
        
        if(done[x]) continue; 
        if(t) k--;
        
        d[x] = y;
        done[x] = 1;
        
        ll u = adj[x].size();
        
        for(int i = 0; i < u; i++) {
            q.push({-(d[x] + adj[x][i].second.second),{-adj[x][i].second.first, adj[x][i].first}});
        }
    }
}
int main()
{IO
#ifndef ONLINE_JUDGE
    freopen("output.txt","w",stdout);
#else
#endif
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,{0ll,w}});
        adj[y].push_back({x,{0ll,w}});
    }
    //for(int i=1;i<=n;i++)cout<<d[i]<<endl;
    
    st.insert(0);
    for(ll i=1;i<=k;i++){
        ll x,y;
        cin>>x>>y;
        adj[1].push_back({x,{i,y}});
        adj[x].push_back({1,{i,y}});
    }
    dijkstra();
    //cout<<st.size()-1<<endl;
    cout<<k<<endl;
    return 0;
}