#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;cin>>T;
	while(T--){
		int n;
		cin>>n;
		char arr[n][n];
		// cout<<n<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				// cout<<i<<j<<T<<endl;
				cin>>arr[i][j];
			}
		}
		bool done = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				// cout<<i<<j<<T<<endl;
				if(arr[i][j]=='1'){
					if(i==n-1 or j==n-1 ){
						// done = true;
					}
					else if(!(arr[i+1][j]=='1' or arr[i][j+1]=='1')){
						done = false;
					}
				}
			}
		}
		if(done){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
		cout<<endl;
	}
}