// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int t;cin>>t;while(t--){
// 		long long int n,k;
// 		cin>>n>>k;
// 		string s;
// 		cin>>s;
// 		sort(s.begin(),s.end());
// 		map<char,int> m,g;
// 		bool great = false;
// 		for(int i=0;i<n;i++){
// 			// cout<<m[s[i]]<<endl;
// 			m[s[i]]++;
// 		}
// 		char culpit;
// 		char max = 'a';
// 		for(auto i=m.begin();i!=m.end();i++){
// 			if(i->second % k !=0 ){
// 				// cout<<i->first<<endl;
// 				great = true;
// 				culpit = i->first;
// 				// break;
// 			}
// 			else if(max<i->first)
// 				max = i->first;
// 			if(i->second >= k){
// 				g[i->first] = i->second;
// 			}
// 		}
// 		if(m.size()==1){
// 			string ans;
// 			for(auto i = m.begin();i!=m.end();i++){
// 				ans += string( (i->second / k) + min((i->second % k),1LL) ,i->first);
// 			}
// 			sort(ans.begin(),ans.end());
// 			cout<<ans<<endl;
// 		}
// 		else if(g.size()<=2 and m.size() == 2){
// 			auto i = g.begin();
// 			if (i->second==k){
// 				string ans;
// 				for(auto i = m.begin();i!=m.end();i++){
// 					ans += string( (i->second / k) + min((i->second % k),1LL) ,i->first);
// 				}
// 				sort(ans.begin(),ans.end());
// 				cout<<ans<<endl;		
// 			}
// 			else{
// 				string ans;
// 				if(i->second>=k){
// 					ans += s[0];
// 					for(int i=k;i<n;i++){
// 						ans += s[i];
// 						// index++;
// 					}
// 				}
// 				else ans = s[k-1];
// 				cout<<ans<<endl;
// 			}
// 		}
// 		else{
// 			string ans;
// 			auto i = g.begin();
// 			// string ans;
// 			if(i->second>=k){
// 				ans += s[0];
// 				for(int i=k;i<n;i++){
// 					ans += s[i];
// 					// index++;
// 				}
// 			}
// 			else ans = s[k-1];
// 			cout<<ans<<endl;
// 		}
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  //if smallest k letters are not all the same, answer is kth smallest letter
  if (s[0]!=s[k-1]){
    cout<<s[k-1]<<endl;
    return;
  }
  cout<<s[0];
  //if remaining letters aren't the same, we append remaining letters to answer
  if (s[k]!=s[n-1]){
    for (int i=k;i<n;i++)
      cout<<s[i];
  }
  else{
    //remaining letters are the same, so we distribute evenly
    for (int i=0;i<(n-k+k-1)/k;i++)
      cout<<s[n-1];
  }
  cout<<endl;
}

int main(){
  int t; cin>>t;
  while (t--)
    solve();
}