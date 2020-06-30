#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		int min = 200001;
		vector<char> uq;
		std::vector<int> len;

		char start  = s[0];
		uq.push_back(start);
		len.push_back(1);

		for(int i=0;i<s.length();i++){
			if(start!=s[i]){
				start = s[i];
				uq.push_back(start);
				len.push_back(1);
			}
			else{
				len[len.size()-1]++;
			}
		}
		// cout<<uq.size()-2<<endl;
		for(int i=0;i<uq.size()-2 and uq.size()>2;i++){
			set<char> se;
			for(int j=i;j<i+3;j++){
				se.insert(uq[j]);
			}
			if(se.size()==3){
				if(min>len[i+1]+2){
					min = len[i+1]+2;
				}
			}	
		}
		
		if(min==200001){
			cout<<0<<endl;
		}
		else{
			cout<<min<<endl;
		}
	}
}