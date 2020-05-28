#include<bits/stdc++.h>
using namespace  std;

int main(){
	int t;cin>>t;while(t--){
		int n,m;
		cin>>n>>m;
		int ans=0;
		if(n%2==0){
			ans = (n/2)*m;
		}
		else if (m%2==0){
			ans = (m/2)*n;
		}
		else {
			ans = (n-1)/2 * m;
			ans += (m/2) + ((m%2)?1:0);
		}
		cout<<ans<<endl;
	}
}