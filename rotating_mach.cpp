#include<bits/stdc++.h>
using namespace std;


int main(){
	// int t;cin>>t;while(t--){
	{
		int n;cin>>n;
		int a[n],b[2*n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			b[n+i] = b[i];
		}
		int max_num = 0;
		for(int i=0;i<n;i++){
			int num = 0;
			for(int j=0;j<n;j++){
				if( b[i+j] == a[j] ){
					num++;
				}
			}
			if(num>max_num){
				max_num = num;
			}
		}
		cout<<max_num<<endl;
	}
}