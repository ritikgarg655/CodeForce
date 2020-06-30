#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int num_odd  = 0, num_even = 0;
		map<int,int> m;
		bool present = false;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			m[arr[i]] = 1;
			if(arr[i]%2==0){
				num_even++;
			}
			else{
				num_odd++;
			}
			// finding is previous present:
			if(m.find(arr[i]-1) != m.end() or m.find(arr[i]+1) != m.end()){
				present = true;
			}
		}
		if(num_odd%2==1 and num_even%2==1 and present){
			cout<<"YES";
		}
		else if(num_odd%2==0 and num_even%2==0){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
}