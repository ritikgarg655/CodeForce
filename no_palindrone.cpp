#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,p;cin>>n>>p;
	string s;
	cin>>s;
	bool done = false;
	string ans = "";
	if(p==1){
		cout<<"NO"<<endl;
		return 0;
	}
	while(!done){
		if(s[n-1]<'a'+p-1){
			s[n-1]++;
			int i;
			bool w = false;
			for(i=0;i<n-1;i++){
				if(s[i]==s[i+1]){
					w = true;
					break;
				}
			}
			for(i=0;i<n-2;i++){
				if(s[i]==s[i+2]){
					w = true;
					break;
				}
			}
			if(!w){
				ans = s;
				done = true;
			}
		}
		else if(n==1){
			cout<<"NO";return 0;
		}
		else{
			s[n-1] = 'a'-1;
			for(int i=n-2;i>=0;i--){
				// cout<<s[i]<<" ";
				if(s[i]<'a'+p-1){
					s[i]++;
					break;
				}
				else{
					s[i] = 'a';
					if(i==0){
						cout<<"NO"<<endl;
						return 0;
						// break;
					}
				}
			}
			cout<<endl;
		}
	}
	cout<<ans<<endl;
}