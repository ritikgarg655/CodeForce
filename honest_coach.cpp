#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		int min_diff = INT_MAX;
		for(int i=1;i<n;i++){
			int diff = abs(arr[i] - arr[i-1]);
			if(diff<min_diff){
				min_diff = diff;
 			}
		}
		cout<<min_diff<<endl;
	}
}