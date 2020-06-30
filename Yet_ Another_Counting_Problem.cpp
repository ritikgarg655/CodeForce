#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int t;cin>>t;while(t--){
		long long int a,b,q;cin>>a>>b>>q;
		long long int time = 1;
		long long int num = a*b/__gcd(a,b); 
		for(long long int i=0;i<q;i++){
			// cout<<i<<endl;
			long long int l,r;cin>>l>>r;
			long long int ans = r-l+1;
			time = 1;
			bool done =false;
			while(1){
				// cout<<time<<endl;
				if(l<max(a,b) and !done) {done = true;ans = ans - (min(max(a,b)-1,r)-l+1);}
				if(l>num*time and l<num*time + max(a,b)) {ans = ans - (min(num*time + max(a,b),r+1) - l) ;}
				else if(r<num*time) { break; }
				else if(((r - max(a,b))/num) - ((l-1)/num) > 0 and (r-max(a,b))>l and (r-max(a,b))/num>time) { time = (r-max(a,b))/num ; ans = ans - ((((r - max(a,b))/num) - ((l-1)/num))* max(a,b)) ;} 
				else if(l<=num*time) { ans = ans - min(max(a,b) , max(0LL, -num*time + r+1)) ;}
				time ++;
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}
}