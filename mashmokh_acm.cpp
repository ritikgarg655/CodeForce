
#include<bits/stdc++.h>
using namespace std;
#define    ll    long long int
ll m=1e9+7,n,c,d,j,k,l,r,x,t,y,u,a[2016][2016],b,z,i,e,f;
int main ()
{
cin>>n>>t;
a[0][1]=1;
for(i=1;i<=t;i++){
    for(j=1;j<=n;j++){
        for(k=j;k<=n;k+=j){
            (a[i][k]+=a[i-1][j])%=m;
        }
    }
}
for(i=1;i<=n;i++){
    (c+=a[t][i])%=m;
}
cout<<c;
}