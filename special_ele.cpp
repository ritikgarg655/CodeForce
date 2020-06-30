#include<bits/stdc++.h>
using namespace std;

// int dfs(int arr[],int index,int n,int temp_sum,int sum){
// 	if(temp_sum==sum){
// 		return 1;
// 	}
// 	if (index==n){
// 		return -1;
// 	}
// 	int a = dfs(arr,index+1,n,temp_sum+arr[index],sum);
// 	int b = dfs(arr,index+1,n,temp_sum,sum);
// 	return max(a,b);
// }

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		map<int,int> m;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			arr[i] = a;
			if(m.find(a)!=m.end()){
				m[a]++;
			}
			else{
				m[a] = 1;
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++){
			int sum = arr[i];
			for(int j=i+1;j<n;j++){
				sum += arr[j];
				if(m.find(sum)!=m.end()){
					ans += m[sum];
					m[sum] = 0;
				}
			}
		}

		// for(int i=1;i<n;i++){
		// 	for(int start = 0;start<n-i;start++){
		// 		int sum = 0;
		// 		for(int j=start;j<=start+i;j++){
		// 			sum += arr[j];
		// 		}
		// 		m[sum] = true;
		// 	}
		// }
		// int ans = 0;
		// for(int i=0;i<n;i++){
		// 	if(m.find(arr[i])!=m.end()){
		// 		ans++;
		// 	}
		// }
		cout<<ans<<endl;
	}
}