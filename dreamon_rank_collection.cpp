#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,x;cin>>n>>x;
		set<int> s;
		for(int i=0;i<n;i++){int a;cin>>a;s.insert(a);}
		set<int>::iterator it;
		it = s.begin();
		int start = 0;
		int ans = 0;
		while(it != s.end()){
			// cout<<*it<<start<<endl;
			if(*it!=start+1){
				if(x<=0) break;
				int used;
				// if(it==s.begin()) used = min(x,*it-start);
				used = min(x,*it-start-1);
				// ans = min(*it,start + x);
				if(used+start+1==*it) ans = *it;
				else ans = used+start;
				x = x-used;
				// ans = *it;
				start = *it;
				// cout<<*it<<start<<used<<endl;
				// ans = min(x,*it-x);
				// start = ;
			}
			else {ans = *it;start = *it;}
			++it;
		}
		if(x>0)
		cout<<ans+x<<endl;
		else cout<<ans<<endl;
	}
}