#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,k;cin>>n>>k;
		string s;
		cin>>s;
		int ans = 0;
		bool arr[n] = {false};
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				for(int j= max(i-k,0);j<=i;j++){
					// cout<<j;
					arr[j] = true;
				}
				for(int j=i;j<=min(i+k,n-1);j++){
					// cout<<j;
					arr[j] = true;
				}
				i+=k;
			}
		}
		for(int i=0;i<n;){
			if(!arr[i]){
				ans++;
				i+=k+1;
			}
			else{
				i++;
			}
		}
		cout<<ans<<endl;
	}
}