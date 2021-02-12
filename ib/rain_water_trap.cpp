#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	stack<pair<int,int>> s;
	int count[n] = {0};
	for(int i=0;i<n;i++){
		count[i] = a[i];
	}
	long long int ans = 0LL;
	s.push_back(make_pair(a[i],0));
	for(int i=1;i<n;i++){
		int index = i;
		while(s.top().first<=a[i]){
			pair<int,int> t = s.top();
			s.pop();
			if(t.second == index-1){
				continue;
			}
			else{
				ans+= (i-t.second-1) * min(t.first,a[i]);
				for(int j = t.second+1;j<i;j++){
					ans -= count[j];
					count[j] = min(t.first,a[i]);
				}
			}
			index = t.second;
		}
		s.push_back({a[i],i});
	}
}

int main(){
	solve();
}