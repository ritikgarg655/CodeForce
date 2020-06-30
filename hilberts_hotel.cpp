#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool done = true;
		set<int> s;
		for(int i=0;i<=n;i++){
			s.insert(i+arr[i%n]);
		}
		if(s.size()==n+1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}