#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	long long int ans = 0LL;
	// finding starting post
	for(int i=0;i<n;i++){
		if(x<=arr[i]){
			// cout<<i;
			long long int sum = 0LL;
			int rem = arr[i] - x;
			sum += arr[i%n]*(arr[i%n]+1)/2;
			sum -= rem*(rem+1)/2; 	
			if(ans<sum){
				ans = sum;
			}
		}
		else{
			for(int k=0;k<arr[i];k++){
				long long int num_Day = 0LL;
				long long int sum = 0LL;
				sum -= k*(k+1)/2;
				num_Day = -k;
				for(int j=i;;j++){
					// if(i==n-1)
					// 	cout<<j<<num_Day;
					// cout<<j<<endl;
					if(num_Day + arr[j%n]>= x){
						int rem;
						// if(i==j){
						// 	rem = x-num_Day-1;
						// 	sum += arr[j%n]*(arr[j%n]+1)/2;
						// 	sum -= rem*(rem+1)/2;
						// }
						// else{
							rem = x-num_Day;
							sum += rem*(rem+1)/2;
						// }
						break;
					}
					else{
						num_Day += arr[j%n];
						sum += arr[j%n]*(arr[j%n]+1)/2;
					}
				}
				if(ans<sum){
					ans = sum;
				}
			}
		}
	}
	cout<<ans<<endl;
}