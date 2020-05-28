#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int m=0;m<t;m++){
		int r,c;
		cin>>r>>c;
		char val[r][c];
		set<char, greater <char>> unique;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>val[i][j];
				unique.insert(val[i][j]);
			}
		}
		set<char> below_com;
		for(int i=0;i<c;i++){
			below_com.insert(val[r-1][i]);
		}
		vector<char> ans;
		bool visited[26] = {false};
		bool below_done = false;
		bool done = true;
		for(auto it = below_com.begin();it!=below_com.end();it++){
			bool temp_done = true;
			for(int i=0;i<r and temp_done;i++){
				for(int j=0;j<c and temp_done;j++){
					if(val[i][j] == *it){
						if(i!=r-1){
							if(!(visited[int(val[i+1][j]) - int('A')] or val[i+1][j] == *it)){
								temp_done = false;
							}
						}
					}
				}
			}
			if(temp_done){
				below_done = true;
				// cout<<*it<<(int(*it)-int('A'));
				visited[int(*it) - int('A')] = true;
				ans.push_back(*it);
			}
		}
		if(!below_done){
			// cout<<'a';
			done = false;
		}
		else{
			while(1){
				bool rem = false;
				bool added = false;
				for(auto it = unique.begin();it!=unique.end();it++){
					if(!visited[int(*it)-int('A')]){
						// ss<<*it;
						rem = true;
						bool temp_done = true;
						for(int i=0;i<r and temp_done;i++){
							for(int j=0;j<c and temp_done;j++){
								if(val[i][j] == *it){
									if(i!=r-1){
										if(!(visited[int(val[i+1][j]) - int('A')] or val[i+1][j] == *it)){
											temp_done = false;
										}
									}
								}
							}
						}
						if(temp_done){
							added = true;
							visited[int(*it) - int('A')] = true;
							ans.push_back(*it);
						}
					}
				}
				if(rem and !added){
					done = false;
					break;
				}
				if(!rem){
					break;
				}
			}
		}
		cout<<"Case #"<<m+1<<": ";
		if(done){
			for(int i=0;i<ans.size();i++){
				cout<<ans[i];
			}
		}
		else{
			cout<<-1;
		}
		cout<<endl;
	}
}