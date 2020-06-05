#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		int arr[n];
		bool visited[n] = {false};
		int min = 0;
		bool ans[n] = {false};
		for(int i=0;i<n;i++){
			cin>>arr[i];
			arr[i]--;
			visited[arr[i]] = true;
			if(arr[i]==min){
				ans[min] = true;
				min = arr[i]+1;
				for(int j= min;j<n;j++){
					if(!visited[j]){
						min = j-1;
						break;
					}
				}
			}
		}
		for(int i=0;i<n-1;i++){
			visited[arr[i]] = false;
			if(arr[i]<=min){
				min = arr[i]-1;
				for(int j= min;j>=0;j--){
					if(!visited[j]){
						min = j-1;
					}
				}
				if(min<0)
					break;
				ans[min] = true;				
			}
		}
		for(int i=0;i<n;i++){
			if(ans[i])
				cout<<"1";
			else
				cout<<"0";
		}
		cout<<endl;
	}
}