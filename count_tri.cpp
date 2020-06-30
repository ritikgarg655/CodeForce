#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	long int count = 0;
	for(int i = a;i<=b;i++){
		count+= 2*i-1;
		// for(int j = c-i+1;j<=c;j++){
		// 	for(int k=c;k<=d;k++){
		// 		if(k<i+j){
		// 			cout<<i<<j<<k<<endl;
		// 			count++;
		// 		}
		// 	}
			// if(i+j>c)

			// count += max(min(i+j-c,d-c+1),0);
			// cout<<count<<endl;
		// }
	}
	cout<<count<<endl;
}