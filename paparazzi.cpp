#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn=1e5+5;
int r,n;
int t[maxn],x[maxn],y[maxn];
int dp[maxn],ans;
int main(){
	scanf("%d%d",&r,&n);
	x[0]=y[0]=1;
	for (int i=1;i<=n;i++){
		dp[i]=-1e9;
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		for (int j=max(i-3000,0);j<=i-1;j++){
			if (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout << ans << '\n';
}