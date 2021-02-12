

#include <bits/stdc++.h>
using namespace std;


#define int         long long
#define double      long double
#define pb          push_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define endl        '\n'
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
int gcd(int a, int b) {if(a>b)swap(a,b) ;  if (a == 0)  return b; return gcd(b % a, a); }

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int r,g,b,w;
        cin>>r>>g>>b>>w;
   
        int minm=min(min(r,g),b);
        // if(r==0||b==0||g==0){
        // cout<<"Yes\n";continue;}
    //   r-=minm;
    //   b-=minm;g-=minm;
    //   w+=3*minm;
       
    //   if(minm==0){
    //   cout<<"No\n";continue;}
     int count=0;
      if(r%2==0)
      count++;
      if(g%2==0)
      count++;
      if(b%2==0)
      count++;
      if(w%2==0)
      {
          count++;
      }
     
     
      if(count>=3)
      {
          cout<<"Yes\n";continue;
      }
    bool flag=false;
    if(minm>=1){
         r-=1;
      b-=1;g-=1;
      w+=3*1;
      int count=0;
      if(r%2==0)
      count++;
      if(g%2==0)
      count++;
      if(b%2==0)
      count++;
      if(w%2==0)
      {
          count++;
      }
     
     
      if(count>=3){
      flag=true;}
   
     
    }
 
    if(flag)
    cout<<"Yes\n";
    else
    {
        cout<<"No\n";
    }
   
    }

    return 0;
}