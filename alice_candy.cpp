#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		long long int alice_sum = 0,bob_sum = 0,alice_index = 0,bob_index = n-1,alice_prev_sum = 0,bob_prev_sum=0;
		int i;
		for(i=0;i<n;i++){
			// cout<<alice_sum<<bob_sum<<endl;
			if(i%2==0){
				// alice
				long long int temp_sum = 0;
				bool done = false;
				int index;
				for(index = alice_index;index<=bob_index;index++){
					if(temp_sum>bob_prev_sum){
						done = true;
						break;
					}
					temp_sum += arr[index];
				}
				alice_prev_sum = temp_sum;
				if(done){
					alice_sum += temp_sum;
					alice_index = index;
				}
				else{
					alice_sum += temp_sum;
					break;
				}
			}
			else{
				// bob
				long long int temp_sum = 0;
				bool done = false;
				int index;
				for(index = bob_index;index>=alice_index;index--){
					if(temp_sum>alice_prev_sum){
						done = true;
						break;
					}
					temp_sum += arr[index];
				}
				bob_prev_sum = temp_sum;
				if(done){
					bob_sum += temp_sum;
					bob_index = index;
				}
				else{
					bob_sum += temp_sum;
					break;
				}
			}
		}
		cout<<i+1<<" "<<alice_sum<<" "<<bob_sum<<endl;
	}
}