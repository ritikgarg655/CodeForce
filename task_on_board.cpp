#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		string s;cin>>s;
		int n;cin>>n;
		int arr[n];
		// map<char,int> inc_char;
		// map<int,vector<int>> m;
		map<char,int,greater<char>> m;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<s.length();i++){
			m[s[i]]++;
		}
		auto it1 = m.begin();
		// it1--;
		string ans(n,' ');
		bool done[n] = {false};
		for(int i=0;i<n;i++){
			vector<int> min_zero;
			for(int j=0;j<n;j++){
				if(arr[j]==0 and !done[j]){
					min_zero.push_back(j);
				}
			}
			while(1){
				if(it1->second<min_zero.size()){
					it1++;
				}
				else{
					break;
				}
			}
			// cout<<min_zero.size();
			for(int j=0;j<min_zero.size();j++){
				done[min_zero[j]] = true;
				ans[min_zero[j]] = it1->first;
				
				// cout<<min_zero[j];
				for(int k=min_zero[j];k>=0;k--){
					arr[k] -= min_zero[j]-k;
				}
				for(int k=min_zero[j];k<n;k++){
					arr[k] -= k-min_zero[j];
				}
			}
			it1++;
		}
		cout<<ans<<endl;
	}
}