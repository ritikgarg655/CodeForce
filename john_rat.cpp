#include<bits/stdc++.h>
using namespace std;

long long int two_pow(long long int n){
	long long int ans = 0LL;
	while(n>0){
		if(n%2==0){
			n = n/2;
			ans++;
		}
		else {
			break;
		}
	}
	return ans;
}

int main(){
	int t;cin>>t;while(t--){
		long long int n;cin>>n;
		long long  int sum = 0LL;
		// cout<<(long long int)((floor(log2(n))==log2(n))?floor(log2(n)):0)+1<<endl;
		long long int start = 1,ans = 0;
		while(start<=n){
			ans += n/start;
			start = start*2;
		}
		cout<<ans<<endl;
	}
}