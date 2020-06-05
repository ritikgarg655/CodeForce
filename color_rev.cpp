#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		// int n1,n2,n3,n4;
		// let
		// n4 = k*k*k;
		int ans = n/(k*k*k + k*k +k +1);
		cout<<ans<<" "<<ans*k<<" "<<ans*k*k<<" "<<ans*k*k*k<<" "<<endl;
	}
}