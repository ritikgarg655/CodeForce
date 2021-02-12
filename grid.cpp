#include<bits/stdc++.h>
using namespace std;
int arr[302][302];
int n,m;
int count1[302][302];
void update(int i,int j){
	if(arr[i][j]!=0)
				if(i!=0 and j!=0){
					count1[i][j-1]++;
					count1[i][j+1]++;
					count1[i-1][j]++;
					count1[i+1][j]++;
				}
				else if((i==0 and j==0)){
					count1[i][j+1]++;
					count1[i+1][j]++;
				}
				else if (i==0 and j==m-1){
					count1[i][j-1]++;
					count1[i+1][j]++;
				}
				else if (i==n-1 and j==0){
					count1[i-1][j]++;
					count1[i][j+1]++;
				}
				else if (i==n-1 and j==m-1){
					count1[i][j-1]++;
					count1[i-1][j]++;
				}
				else {
					if(i==0){
						count1[i][j-1]++;
						count1[i][j+1]++;
						count1[i+1][j]++;
					}
					if(i==n-1){
						count1[i][j-1]++;
						count1[i][j+1]++;
						count1[i-1][j]++;
					}
					if(j==0){
						count1[i+1][j]++;
						count1[i-1][j]++;
						count1[i][j+1]++;
					}
					if(j==m-1){
						count1[i-1][j]++;
						count1[i+1][j]++;
						count1[i][j-1]++;
					}
				}
}

int main(){
	int t;cin>>t;
	while(t--){
		n=0;m=0;
		cin>>n>>m;
		// int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>arr[i][j];
				count1[i][j]=0;
			}
		}
		// int count1[n][m]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				update(i,j);
			}
		}
		bool ans = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				// cout<<arr[i][j]<<count1[i][j]<<endl;
				if(arr[i][j]==0) continue;
				if(arr[i][j]!=count1[i][j] ){
					int num = (arr[i][j]-count1[i][j]);
					if(num<0){
						arr[i][j] = count1[i][j];
					}
					if(j<m-1 and num>0){
						if(arr[i][j+1]==0){
							arr[i][j+1] = count1[i][j+1];
							num--;
							update(i,j+1);
						}
					}
					if(i<n-1 and num>0){
						if(arr[i+1][j]==0){
							arr[i+1][j] = count1[i+1][j];
							num--;
							update(i+1,j);
						}
					}
					if(num>0 and i>0){
						if(arr[i-1][j]==0){
							arr[i-1][j] = 1;
							num--;
							update(i-1,j);
						}
					}
					if(num>0 and j>0){
						if(arr[i][j-1]==0){
							arr[i][j-1] = 1;
							num--;
							update(i,j-1);
						}
					} 
					if(num>0){
						ans = false;
						break;
					}
					arr[i][j] = count1[i][j];
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]!=0)
				arr[i][j] = count1[i][j];
			}
		}
		if(ans){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}