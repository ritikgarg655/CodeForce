#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		long int n,l,r;cin>>n>>l>>r;
		// l--;r--;
		// int arr[n*(n-1) + 2];
		long int num_ver = 2;
		// cout<<l-1;
		for(long int i = 3;i<=n+2;i++){
			// cout<<((i-1)*(i-2))<<endl;
			if((l-1)/((i-1)*(i-2))==0){
				num_ver = i-1 ;
				break;
			}
		}
		int end_ver = n;
		for(long int i = 3;i<=n+2;i++){
			// cout<<(l-1)/((i-1)*(i-2))<<endl;
			if((r-1)/((i-1)*(i-2))==0){
				end_ver = i-1 ;
				break;
			}
		}
		long int i;
		// cout<<end_ver<<endl;
		for(i=num_ver-1;i<end_ver;i++){
			long int start = 1;
			long int j;
			for(j=max(i,l);j<i+2*(i+1) and j<r;j++){
				// cout<<j;
				if(j%2==0){
					cout<<start<<" ";
					start++;
				}
				else{
					cout<<num_ver<<" ";
				}
			}
			if(j>=r){
				break;
			}
			num_ver++;
			i = j;
		}
		// cout<<is;
		if(i==(n*(n-1)+1) and i<=r)
			cout<<1;
		cout<<endl;
	}
}	