#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;int arr[n];
	long long int sum = 0;
	long long int max1 = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
		if(max1<arr[i]){
			max1 = arr[i];
		}
	}
	// if(x<max){
	// 	sum = max;
	// }
	cout<<max((long long int)ceil(sum/((float)(n-1))),max1)<<endl;
}