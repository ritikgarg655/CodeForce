#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		long long int h,c,t;cin>>h>>c>>t;
		if(t*2<=((h+c))){
			cout<<2<<endl;
			continue;
		}
		long long int n;
		{
			n = (t-c)/((2*t)-h-c);
			double a1 = ((n*h + ((n-1)*c))*1.0) / (2*n-1);
			n++;
			double a2 = ((n*h + ((n-1)*c))*1.0) / (2*n-1);
			if(abs(t-a1)<=abs(t-a2)){
				n--;
			}
		}
		cout<<(2*n)-1<<endl;
	}
}