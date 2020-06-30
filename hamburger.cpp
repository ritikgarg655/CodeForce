#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int req_b = 0,req_s=0,req_c = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='B'){
			req_b++;
		}
		else if (s[i]=='S'){
			req_s++;
		}
		else{
			req_c++;
		}
	}
	int nb,ns,nc;
	cin>>nb>>ns>>nc;
	int pb,ps,pc;
	cin>>pb>>ps>>pc;
	long long int r;
	cin>>r;
	int shop_b;// = nb/req_b;
	int shop_s;// = ns/req_s;
	int shop_c;// = nc/req_c;
	if(req_b>0)
		shop_b = nb/req_b;
	else{
		shop_b = INT_MAX;
	}
	if(req_c>0)
		shop_c = nc/req_c;
	else{
		shop_c = INT_MAX;
	}
	if(req_s>0)
		shop_s = ns/req_s;
	else{
		shop_s = INT_MAX;
	}
	// cout<<req_c<<req_s<<req_b;
	// cout<<shop_b<<shop_c<<shop_s;
	long long int ans=min(min(shop_c,shop_s),shop_b);
	nb -= ans*req_b ;
	ns -= ans*req_s ;
	nc -= ans*req_c ;
	// cout<<ans;
	// cout<<nb<<nc<<ns;
	while((nc>0 and req_c>0) or (ns>0 and req_s>0) or (nb>0 and req_b>0)){
		if(req_b>0)
			shop_b = nb/req_b;
		else{
			shop_b = INT_MAX;
		}
		if(req_c>0)
			shop_c = nc/req_c;
		else{
			shop_c = INT_MAX;
		}
		if(req_s>0)
			shop_s = ns/req_s;
		else{
			shop_s = INT_MAX;
		}
		// shop_s = ns/req_s;
		// shop_c = nc/req_c;
		// cout<<nb<<nc<<ns;
	// cout<<shop_b<<shop_c<<shop_s;
		if(shop_b==0){
			if(((req_b-nb)*pb) <=r){
				r -= (req_b-nb)*pb;
				shop_b++;
				nb = req_b;
			}
			else{
				break;
			}
		}
		if(shop_c==0){
			if(((req_c-nc)*pc) <=r){
				r -= (req_c-nc)*pc;
				shop_c++;
				nc = req_c;
			}
			else{
				break;
			}
		}
		if(shop_s==0){
			if(((req_s-ns)*ps) <=r){
				r -= (req_s-ns)*ps;
				shop_s++;
				ns = req_s; 
			}
			else{
				break;
			}
		}
		int temp  =  min(min(shop_c,shop_s),shop_b);
		nb -= temp*req_b ;
		ns -= temp*req_s ;
		nc -= temp*req_c ;
		ans += temp;
		// cout<<temp;
	}
	long long int tot_pr = (req_b*pb) + (req_c*pc) + (req_s*ps);
	// cout<<tot_pr;
	ans += r/tot_pr;
	cout<<ans<<endl;
}