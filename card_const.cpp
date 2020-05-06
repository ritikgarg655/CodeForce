#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		long long int level = 0;
		long long int used_card = 0;
		
		while(used_card<=n){
			level++;
			used_card = (3*pow(level,2) + level) / 2;
		}
		level--;
		long long int ans = 0;
		while(n>1){
			long long int curr_used = (3*pow(level,2) + level) / 2;
			long long int num =  n/curr_used;
			ans+=num;
			// cout<<curr_used<<endl;
			n -= (num*curr_used);
			level--;
		}
		cout<<ans<<endl;
	}
}
