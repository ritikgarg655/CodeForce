#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2){
	if(p1.second != p2.second and (p1.first < p2.first)){
		return true;
	}
	return false;
}

int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		vector<pair<int,int>> arr;
		int temp_sort[n];
		vector<pair<int,int>> b_rec[100001];
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			temp_sort[i] = a;
			arr.push_back(make_pair(a,0));
		}
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			b_rec[arr[i].first].push_back(make_pair(a,i));
			arr.push_back(make_pair(arr[i].first,a));
			// if(a==1){
			// 	b[i] = true;
			// }
			// else
			// 	b[i] = false;s
		}
		sort(temp_sort,temp_sort+n);
		bool fin_done = true;
		for(int i=0;i<n;i++){
			if(arr[i].first == temp_sort[i]){
				// cout<<i<<endl;
				continue;
			}
			bool done = false;
		// 	int index_1 = -1,index_2 = -1;
			for(int k=0;k<b_rec[temp_sort[i]].size();k++){
				for(int j=0;j<b_rec[arr[i].first].size();j++){
					if(b_rec[temp_sort[i]][k].first != b_rec[arr[i].first][j].first and b_rec[arr[i].first][j].first!=-1 and b_rec[temp_sort[i]][k].first!=-1){
						b_rec[arr[i].first][j].first = -1;
						done = true;
						// cout<<i<<endl;
					}
				}
				if(done){
					break;
				}
			}
			if(!done){
				fin_done = false;
				break;
			}
		}

		// bool done = true;
		// for(int i=1;i<n;i++){
		// 	if(arr[i]<arr[i-1]){
		// 		done = false;
		// 		break;
		// 	}
		// }	
		if(fin_done){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;	
		}
	}
}