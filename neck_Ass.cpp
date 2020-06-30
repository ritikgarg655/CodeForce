#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,k;
		// cout<<t;
		cin>>n>>k;
		// cout<<t;
		string s;
		// cout<<t;
		cin>>s;
		// cout<<t;
		map<char,int> m;
		for(int i=0;i<s.length();i++){
			m[s[i]]++;
		}
		// finding div od k;
		vector<int> div;
		// div.push_back(k);
		for(int i=1;i<=min(n,k);i++){
			if(k%i==0){
				div.push_back(i);
			}
		}
		sort(div.begin(),div.end(),greater<int>());
		int ans = 0;
		for(int i=0;i<div.size();i++){
			auto it = m.begin();
			int temp_ans = 0;
			while(it!=m.end()){
				temp_ans +=(it->second / div[i]);
			}
			if(temp_ans>ans){
				ans = temp_ans;
			}
		}
		cout<<ans<<endl;
	}
}