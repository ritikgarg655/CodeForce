#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int len = 0;
		int ans_len = 0;
		vector<int> ans;
		while(n>0){
			int digit = n%10;
			n = n/10;
			if(digit!=0){
				ans_len++;
				ans.push_back(digit*pow(10,len));
			}
			len++;
		}
		cout<<ans_len<<endl;
		for(int i =0;i<ans_len;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}