#include<bits/stdc++.h>
using namespace std;

int  main(){
	long long int  t;cin>>t;
	for(long long int  m=0;m<t;m++){
		char ans[10] = "";
		long long int  u;cin>>u;
		vector<pair<int, char>> v;
		bool alphs[26] = {false};
		for(long long int  i=0;i<10000;i++){
			// cout<<i<<endl;
			string a;
			string s; 
			string c;
			cin>>a;
			// cout<<a<<"e"<<endl;
			if(a.length()==1) {
				cin>>c;
				// cout<<a;
				v.push_back(make_pair((int)(a[0]-'0'),c[0]));
				alphs[(int)(c[0]-'A')] = true;
			}
			else {
				cin>>s;
				// unsigned int number_of_digits = 0;
				// int n = a,base  = 10;
				// do {
				//      ++number_of_digits; 
				//      n /= base;
				// } while (n);
				if(a.length() == s.length() and a!="-1") {v.push_back(make_pair((int)(a[0]-'0'), s[0])); }
				for(long long int  j=0;j<s.length();j++) alphs[(int )(s[j]-'A')] = true;
			}
		}
		sort(v.begin(),v.end());
		// long long int  start = 1;
		bool ans_inc[26] = {false};
		// cout<<v.size();
		for(long long int  j=0;j<v.size();j++){
			if(!ans_inc[(int)(v[j].second-'A')] and !ans[v[j].first]){
				ans[v[j].first] = v[j].second;
				// cout<<v[j].first<<endl;
				ans_inc[(int )(v[j].second-'A')] = true;
 				// start++;
			}
		}
		// start = 0;
		for(long long int  i=0;i<26;i++){
			for(int  j=0;j<10;j++)
				if(!ans[j] and !ans_inc[i] and alphs[i]) {
					ans[j] = 'A' + i;
					break;
					// start++;
				}
		}
		cout<<"CASE #"<<m+1<<": ";
		for(long long int  i=0;i<10;i++) cout<<ans[i];
		cout<<endl;
	}	
}
