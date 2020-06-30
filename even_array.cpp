#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		// cout<<t;
		int n;cin>>n;
		int arr[n];
		vector<int> even,odd;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if((arr[i]%2) != (i%2)){
				if(arr[i]%2==0){
					even.push_back(arr[i]);
				}
				else{
					odd.push_back(arr[i]);
				}
			}
		}
		if(even.size()==odd.size()){
			cout<<even.size()<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}