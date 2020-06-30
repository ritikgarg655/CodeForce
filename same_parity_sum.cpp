#include<bits/stdc++.h>
using namespace std;

int rec_find_sum(int rem_n,int rem_k,int ans[],int reminder){
	if((rem_n<=0 and rem_k!=0) or (rem_k==0 and rem_n!=0)){
		return -1;
	}
	else if(rem_k==0 and rem_n==0){
		return 1;
	}
	int temp_n = rem_n;
	while(temp_n>0){
		temp_n--;
		if(temp_n%2==reminder){
			int a = rec_find_sum(rem_n-temp_n,rem_k-1,ans,temp_n%2);
			if(a>=1){
				ans[a-1] = temp_n;
				return a+1;
			}
		}
	}
	return -1;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n-k+1>0 and (n-k+1)%2!=0){
			cout<<"YES"<<endl;
			for(int i=0;i<k-1;i++){
				cout<<1<<" ";
			}
			cout<<n-k+1<<endl;
		}
		else if(n-2*(k-1)>0 and (n-2*(k-1))%2==0){
			cout<<"YES"<<endl;
			for(int i=0;i<k-1;i++){
				cout<<2<<" ";
			}
			cout<<n-2*(k-1)<<endl;
		}
		else{
			cout<<"NO"<<endl;		
		}
	}
}