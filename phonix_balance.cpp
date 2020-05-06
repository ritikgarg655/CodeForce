#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		long long int sum = 0,n;cin>>n;
		nfor(int i=1;i<=n;i++){
			if(i<n/2) sum += pow(2,i);
			else if(i!=n) sum -= pow(2,i);
			else sum += pow(2,i);
		}
		cout<<abs(sum)<<endl;
	}
}