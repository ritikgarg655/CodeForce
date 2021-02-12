#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n];
	map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	int num_4 = 0;
	int num_2 = 0;
	for(auto it= m.begin();it!=m.end();it++){
		if(it->second /4 > 0){
			num_4 += it->second/4;
		}
		num_2 += (it->second - ((it->second/4)*4))/2;
	}	
	int q;cin>>q;
	for(int i=0;i<q;i++){
		char c;cin>>c;int temp;cin>>temp;
		bool plus;
		int prev = m[temp];
		if(c == '+'){
			// cout<<"des";
			plus = true;
			m[temp]++;
		}
		else{
			plus = false;
			m[temp]--;
		}
		cout<<num_4<<num_2<<prev;
		if(prev/4>0 and prev%4==1 and !plus){
			num_4--;
		}
		else if((prev - prev/4)/2>0 and (prev - ((prev/4)*4))%2==0 and !plus){
			num_2--;
		}
		else if(prev%4==3 and plus){
			num_4++;
		}
		else if((prev )%2==1 and plus){
			num_2++;
		}
		cout<<num_4<<num_2<<endl;
		if(num_4>0 and (num_2>1 or num_4>1)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}