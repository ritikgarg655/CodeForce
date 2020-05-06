#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	for(int m=1;m<=t;m++){
		int x,y;cin>>x>>y;
		string s;
		cin>>s;
		int n = s.length();
		int time = 0;
		int start_X = x;
		int start_Y = y;
		bool done = false;
		cout<<"CASE #"<<m<<": ";
		for(int i=-1;i<n and !done;i++){
			if(i==-1) {
				if(abs(start_X) +abs(start_Y)==time) {cout<<time; done = true;}
			}
			else{
				if(s[i] == 'N'){
					start_Y++;
				} 
				else if(s[i] == 'S'){
					start_Y--;
				}
				else if(s[i] == 'E'){
					start_X++;
				}
				else if(s[i] == 'W'){
					start_X--;
				}
				time++;
				if(time >= abs(start_X) +abs(start_Y)) {cout<<time; done = true;}
			}
		}
		if(!done) cout<<"IMPOSSIBLE";
		cout<<endl;
	}
}