#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int m=0;m<t;m++){
		long long int count = 0LL;
		int n,k;
		cin>>n>>k;
		int curr = 0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			// cout<<curr;
			if(a==k){
				curr = k;
			}	
			else if(a==curr-1){
				curr--;
				if(curr==1){
					count++;
				}
			}
			else{
				curr = 0;
			}
		}
		cout<<"Case #"<<m+1<<": ";
		cout<<count<<endl;
	}
}