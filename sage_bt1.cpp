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

void rearrange(int arr[], int n)
{ int i;
  int ans[n];
    // initialize index of first minimum and first
    // maximum element
    int max_ele = n-1;
    int min_ele = 0;
    // traverse array elements
    for (int i = 0; i < n; i++) {
        // at even index : we have to put maximum element
        if (i % 2 == 0) {
            ans[i] = arr[max_ele];
            max_ele -= 1;
        }
        // at odd index : we have to put minimum element
        else {
            ans[i] = arr[min_ele];
            min_ele += 1;
        }
    }
     fo(i,0,n)
      cout<<ans[i]<<" ";
      cout<<endl;
}
signed main()
{
    fast;
    int t,i;
 
       int n;
       cin>>n;
       int arr[n];
       fo(i,0,n)
       {
           cin>>arr[i];
       }
       if(n%2)
       cout<<n/2<<endl;
       else
       cout<<n/2-1<<endl;
       sort(arr,arr+n);
       rearrange(arr,  n);
    //   fo(i,0,n)
    //   cout<<arr[i]<<" ";
    //   cout<<endl;

   
   
    return 0;
}