#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	string arr;
	cin>>arr;
	int sum[s.length()];
	for(int i=0;i<s.length();i++){
		int a = arr[s[i]-'a']-'0';
		if(i==0){
			sum[0] = a;
		}
		else{
			sum[i] = a + sum[i-1];
		}
	}
	int tolerance = 0;
	cin>>tolerance;
	map<string,bool> ans;
	for(int i=0;i<s.length();i++){
		string temp = "";
		for(int j=i;j<s.length();j++){
			temp += s[j];
			int len = temp.length();
			int zero;
			if(i!=0){
				zero = sum[j] - sum[i-1];
			}
			else{
				zero = sum[j];
			}
			zero = len-zero;
			if(zero<=tolerance){
				// cout<<temp<<endl;
				ans[temp] = true;
			}
			else{
				break;
			}
		}
 	}
 	cout<<ans.size()<<endl;
}