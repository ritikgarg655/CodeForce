#include<bits/stdc++.h>
using namespace std;
map<long long int,int> m;
map<long long int,long long int> m2;
int main(){
	int n;cin>>n;int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// prefix sum
	long long int ans = 0;
	long long int sum  = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
		// m[sum]++;
		// prev found
		// m2[sum] = 
		if(i!=n-1){
			m[sum]++;
		}
		if(m.find(sum/2)!=m.end())
			m2[sum] = (long long int)m2[sum]  + (long long int)m[sum/2];
	}
	if(sum%3==0 and sum!=0){
		auto it = m2.find((sum/3)*2);
		// auto it2 = m.find(sum/3);
		if(it!=m2.end()){
			// cout<<sum;
			ans += (long long int)it->second;
			// cout<<ans;
		}
	}
	else if(sum==0){
		auto it = m.find(0); 
		if(it!=m.end() and (it->second) > 1){
			// cout<<i;
			ans += (long long int)(it->second-1) * (long long int)(it->second )/2;
		}
	}
	
	cout<<ans<<endl;
}