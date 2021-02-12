# pragma GCC optimize("Ofast")
# pragma GCC optimization ("unroll-loops")
# include "bits/stdc++.h"
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
# define testcase ll t=1; cin>>t; while(t--)
# define ll             long long
# define ull            unsigned long long
# define countbit       __builtin_popcount
# define gcd            __gcd
# define all(s)         s.begin(),s.end()
# define sz(x)          (int)((x).size())
# define pb(x)          push_back(x)
# define mp(x,y)        make_pair(x,y)
# define mod 1000000007
# define rep(i,j,n)  for(int i=j; i<n; i++)
# define rrep(i,n,j) for(int i=n-1; i>=j; i--)
# define flag(f) (f?"Yes":"No")<<"\n"
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
using namespace std;
const ll INF = 998244353;
typedef vector<vector<int> > mat;
typedef pair<int, int> pi; 
typedef pair<pi,int> piii;
#define N 3001
mat adj(N);
int dp[N][N];
int parent[N][N];
 
void printPath(int i, int p)
{
    if(i==0) 
    return ;
    printPath(p, parent[i][p]);
    printf("%d ", i);
}
 
int main()
{
  int n, m, k;
  set<piii> s; 
  scanf("%d%d%d", &n, &m, &k);
 
  while(m--)
  {
      int a, b; scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  
  while(k--)
  {
     int a, b, c; scanf("%d%d%d", &a, &b, &c); 
     s.insert(mp(mp(a,b),c));
  }
  queue<pi> que;
 
  que.push(mp(1, 0));
  int i, p;
  while(!que.empty())
  {
       i= que.front().first;
       p= que.front().second;
  
       //   cout<<i<<" ";
       if(i==n) break;
       que.pop();
 
      for(int j=0; j<adj[i].size(); j++)
      {
          int k = adj[i][j];
         
          if(s.find(mp(mp(p, i),k)) != s.end() || dp[k][i]!=0)
                 continue;
          
         // cout<<k<<" ";
          dp[k][i] = dp[i][p] + 1;
          parent[k][i] = p;
          que.push(mp(k, i));
      }
  }
  cout<<"\n";
  if(i!=n)
  {
      printf("-1\n");
  }else{
      printf("%d\n", dp[i][p]);
      printPath(i, p);
      printf("\n");
  }
 
 
	return 0;
}