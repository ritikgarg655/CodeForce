#include <bits/stdc++.h>
using namespace std;

#define int         long long
#define double      long double
#define pb          push_back
#define pf          push_front
#define mp(a,b)     make_pair(a,b)
#define vi          vector<int>
#define pii         pair<int,int>
#define mii         map<int,int>
#define mpi         map<pair<int,int>,int>
#define vp          vector<pair<int,int> >
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define endl        '\n'
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
#define fast        std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod         1000000007
#define dom         998244353
#define pi          3.14159265
#define mini        2000000000000000000
#define time_taken 1.0 * clock() / CLOCKS_PER_SEC
//mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) {if(a>b)swap(a,b) ;  if (a == 0)  return b; return gcd(b % a, a); }


signed main()
{
    // fast;
    int t;
    cin>>t;
    while(t--)
    {
       int n,i,j;
       cin>>n;
       int a[n];
      
       int b[n];
       fo(i,0,n)
       {
           cin>>a[i];
           b[i]=a[i];
       }
    
      
       int maxm=0;
       sort(b,b+n);

    int cnt=0;
       fo(i,0,n-1)
       {
            cnt=0;
           while(b[i]==b[i+1]){
           cnt++;i++;
           if(i==n-1){
           break;}
               
           }
        //   cout<<cnt;
           maxm=max(maxm,cnt);
       }
   
       if((maxm+1)>n/2){
       cout<<"NO"<<endl;
       continue;
     }
       
       cout<<"YES\n";
      
           fo(i,0,n-1)
           {
               fo(j,i+1,n)
               {
                   if(a[i]!=a[j])
                   cout<<i+1<<" "<<j+1<<endl;
               }
           }       
    }
    
    return 0;
}