#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		int arr[n];
		set<int> s;
		for(int i=0;i<n;i++) {
			cin>>arr[i];
			s.insert(arr[i]);
		}
		if(s.size()>k) {
			cout<<-1<<endl;
			continue;
		}
		else{
			int seq[k];
			if(s.size()<=k){
				set<int>::iterator it = s.begin();
				for(int i=0;i<k;i++){
					if(i<s.size()){
						seq[i] = *it;
						it++;

					}
					else
						seq[i] = 1;
				}
			}
			int num_Seq = 1;
			cout<<n*k<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<k;j++)
					cout<<seq[j]<<" ";
			}
			cout<<endl;
		}
	}
}