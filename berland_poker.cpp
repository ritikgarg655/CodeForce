#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int ans;
		if((n/k)>=m){
			ans = m;
		}
		else{
			ans = n/k - ((m-(n/k))/(k-1) + (((m-(n/k))%(k-1)==0)?0:1) );
		}
		cout<<ans<<endl;
	}
}