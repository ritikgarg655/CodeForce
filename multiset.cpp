#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	multiset<int> m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		m.insert(a);
	}
	for(int i=0;i<k;i++){
		int query;
		cin>>query;
		if(query>0){
			m.insert(query);
		}
		else{
			query = abs(query);
			multiset<int>::iterator add = m.begin();
			for(int j=1;j<query;j++){
				add++;
			}
			m.erase(add);
		}
	}
	if(m.empty()){
		cout<<0<<endl;
	}
	else{
		auto a = m.begin();
		cout<<*a<<endl;
	}
}
