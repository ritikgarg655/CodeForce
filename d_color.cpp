#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	multiset<pair<int,int>,greater<pair<int,int>>> arr;
	long long int sum = 0LL;
	for(int i=0;i<m;i++){
		int a;cin>>a;
		sum+=a;
		arr.insert(a);
	}
	multiset<ipair<int,int>,greater<pair<int,int>>>::iterator it;
	it = arr.begin();
	int start = 1;
	int end = 1;
	if(sum<n) {cout<<-1<<endl;return 0;}
	set<pair<int,int>> ans;
	for(int i = 0;it!=arr.end();it++){
		if(sum<n-end) {cout<<-1;return 0;}
		else if(end >= n+1) {cout<<-1;return 0;}
		else if(sum==n-end+1){
			ans.insert(make_pair(  ,start));
			end = end+*it.first;
			start = end;
			sum -= *it.first;
		}
		else{
			ans[i] = start;
			end = start + *it.first;
			start = start+1;
			sum -= *it.first;
		}
		i++;
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}