#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		long long int n,x;
		cin>>n>>x;
		long long int ans =0;
		// cout<<n<<x;
		if(n==x){
			// cout<<n<<x;
			ans = 0;
		}
		else if (n>x and n%x==0 and (n/x)%2==0){
			long long int num = n/x;
			// cout<<n<<x;
			while(num>1){
				if(num%8==0){
					num = num/8;
					ans ++;
				}
				else if(num%4==0){
					num = num/4;
					ans ++;
				}
				else if(num%2==0){
					num = num/2;
					ans ++;
				}
				else {
					ans = -1;
					break;
				}
			}
		}
		else if (n<x and x%n==0  and (x/n)%2==0){
			long long int num = x/n;
			// cout<<n<<x<<num;
			while(num>1){
				// cout<<num<<endl;
				// if(n==1001){
				// 	cout<<num<<" ";
				// }
				if(num%8==0){
					num = num/8;
					ans ++;
				}
				else if(num%4==0){
					num = num/4;
					ans ++;
				}
				else if(num%2==0){
					num = num/2;
					ans ++;
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		else{
			ans= -1;
		}
		cout<<ans<<endl;
	}	
}