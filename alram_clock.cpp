#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		long long int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(c<=d){
			if(a<=b){
				cout<<b<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else{
			long long int ans = b;
			if(a>b){
				ans += (((a-b)/(c-d))*c + (((a-b)%(c-d)!=0)?c:0));
			}
			cout<<ans<<endl;
		}
	}
}