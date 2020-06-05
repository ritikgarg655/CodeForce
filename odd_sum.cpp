#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int arr[n];
		int num_even = 0,num_odd = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]%2==0){
				num_even++;
			}
			else{
				num_odd++;
			}
		}
		bool done = true;
		if(num_odd==0){
			done = false;
		}
		else if(n==x){
			if(num_odd%2==0){
				done = false;
			}
		}
		else if (n==num_odd){
			if(x%2==0){
				done = false;
			}
		}
		else{
			x--;
			num_odd--;
			if(x>0)
				if(x%2==0){
					if(x>(num_even- num_even%2 + num_odd - num_odd%2)){
						done = false;
					}
				}
				else {
					if(x>(num_even- (num_even%2?0:1) + num_odd - num_odd%2)){
						done = false;
					}
				}
		}
		if(done)
			cout<<"YES";
		else 
			cout<<"NO";
		cout<<endl;
	}
}