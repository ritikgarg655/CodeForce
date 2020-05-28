#include<bits/stdc++.h>
using namespace std;

bool check_sq(long long int sum){
	long double sq = sqrt(sum);
	return ((sq-floor(sq))==0);	
}

int main(){
	int t;
	cin>>t;
	for(int m=0;m<t;m++){
		int n;
		cin>>n;
		long long int arr[n];
		long long int sum[n] = {0};
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(i==0){
				sum[0] = arr[i];
			}
			else{
				sum[i] = sum[i-1] + arr[i]; 
			}
		}
		long long int ans = 0LL;
		for(int i=0;i<n;i++){
			if(check_sq(sum[i])){
				ans++;
			}
			for(int j=0;j<i;j++){
				if(check_sq(sum[i] - sum[j])){
					ans++;
				}
			}
		}
		cout<<"Case #"<<m+1<<": ";
		cout<<ans<<endl;
	}
}