#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		char arr[n][m];
		int count = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				if(arr[i][j]=='.'){
					count++;
				}
			}
		}
		int price = 0;
		int double_count = 0;
		if(2*x>y){
			for(int i=0;i<n;i++){
				// int temp_count = 0;
				for(int j=1;j<m;j++){
					if(arr[i][j] == arr[i][j-1] and arr[i][j]=='.'){
						double_count++;
						j++;
					}
				}
				// double_count += temp_count;
			}
			// cout<<(count - (2*double_count))<<endl;
			price = ((count - (2*double_count))*x) + (double_count*y);
		}
		else{
			price = count*x;
		}
		cout<<price<<endl;
	}
}