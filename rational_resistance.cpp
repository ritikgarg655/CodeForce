#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int a,b,ans = 0;
	cin>>a>>b;
	while(a>0){
		if(a>=b){
			long long int temp = a;
			ans += temp/b;
			a = a%b;
		}
		else{
			long long int temp = b;
			ans += b/a;
			temp = a;
			a = b%a;
			b = temp;
		}
	}
	cout<<ans<<endl;	
}