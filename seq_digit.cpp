#include<bits/stdc++.h>
using namespace std;

int min_ele(long long int n){
	int min = 9;
	while(n>0){
		int ele = n%10;
		n = n/10;
		if(min>ele){
			min = ele;
		}
	}
	return min;
}

int max_ele(long long int n){
	// string s = to_string(n);
	// sort(s.begin(),s.end());
	// return stoi(s[s.length()-1]);
	int max = 0;
	while(n>0){
		int ele = n%10;
		n =n /10;
		if(max<ele){
			max = ele;
		}
	}
	return max;
}

int main(){
	int t;cin>>t;
	// cout<<t;
	while(t--){
		// cout<<t;
		long long int a,k;
		cin>>a>>k;
		// cout<<a<<k;
		for(int i=0;i<k-1;i++){
			// cout<<a;
			if(min_ele(a)==0){
				break;
			}
			a = a + min_ele(a)*max_ele(a);
		}
		cout<<a<<endl;
	}
}