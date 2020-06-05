#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		string s;
		cin>>s;
		// assuming start with 0
		// assuming start with 1
		int count_1 = 0;
		int ans_1 =0;
		int count_0 = 0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='1'){
				count_1++;
			}
			if(s[i]=='0')
				count_0++;
		}	
		int ans = INT_MAX ;
		int prev_zero = 0;
		int prev_one = 0;
		// cout<<count_0<<count_1<<endl
		for(int i=0;i<s.length();i++){
			if(s[i]=='0'){
				prev_zero++;
			}
			else{
				prev_one++;
			}
			// cost for one:
			int temp_ans = max(count_1 - prev_one + prev_zero,0);
			temp_ans = min(temp_ans, max(0,count_0 - prev_zero +prev_one) );
			ans = min(ans,temp_ans);
		}
		cout<<ans<<endl;
	}
}