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

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  for(int q=1;q<=t;q++)
  {
    cout<<"Case #"<<q<<": ";

int n,m,k,i,j;
cin>>n>>m;
int a[n];
fo(i,0,n)
{
    cin>>a[i];
}
int sum=0;
int mm=INT_MAX;
fo(k,1,m+1)
{
    sum=0;
    fo(i,0,n)
    {
        if(a[i]==1&&k==m)
        sum+=1;
        else if(a[i]==m&&k==1)
        sum+=1;
        else
        {
           int aa= abs(a[i]-k);
            int b=abs(m-a[i]+k);
            int c=abs(a[i]+m-k);
            sum+=min(min(aa,b),c);
        }
        
        
        
    }
    // cout<<sum<<" ";
    mm=min(mm,sum);
    
}
cout<<mm<<endl;


  } 
  

    return 0;
}