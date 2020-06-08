#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;while(t--){
		int n,m;cin>>n>>m;
		int num_col = m;
		int num_row = n;
		bool col[m] = {false};
		bool row[n] = {false};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int a;
				cin>>a;
				if(a==1){
					if(col[j]!=true){
						col[j] = true;
						num_col--;
					}
					if(row[i]!=true){
						row[i] = true;
						num_row--;
					}
					// num_row--;
					// num_col--;
				}
			}
		}
		int num = 0;
		if(num_col<=0 or num_row<=0){
			num = 0;
		}
		else{
			num = min(num_row,num_col);
		}
		if(num%2==0){
			cout<<"Vivek"<<endl;
		}
		else{
			cout<<"Ashish"<<endl;
		}
	}
}