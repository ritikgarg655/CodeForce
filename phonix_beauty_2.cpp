#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		long long int n,k;cin>>n>>k;
		long long int arr[n];
		set<long long int> s;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			s.insert(arr[i]);
		}
		if(s.size()>k) {cout<<-1<<endl; continue;}
		else {
			long long int ans[10001];
			long long int siz =0,index = 0;
			for(int i=0;i<n;){
				// long long int start = arr[i];
				int len = 0;
				for(auto it = s.begin();it!=s.end();it++){
					len++;
					if(arr[i]==*it) {i++; if(i==n) break;} 
				}
				siz += len;
			}
			cout<<siz<<endl;
			for(int i=0;i<siz/s.size();i++){
				for(auto it = s.begin();it!=s.end();it++){
					cout<<*it<<" ";
				}
			}
			int len = siz%s.size();
			for(auto it = s.begin();it!=s.end();it++){
				if(len ==0 ) break;
				cout<<*it<<" ";
				len--;
			}
			cout<<endl;
		}
	}
}