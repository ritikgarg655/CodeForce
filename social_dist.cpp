#include<bits/stdc++.h>
using namespace std;

// int min_left(){

// }

int main(){
	int t;cin>>t;while(t--){
		int n;
		cin>>n;int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<int> ans;
		int prev = arr[0];
		bool inc = true;
		int index = 0;
		for(int i=0;i<n;i++){
			if(arr[i]==1){
				index = i;
				break;
			}	
		}
		stack<pair<int,int>> s;
		s.push(make_pair(index,0));
		stack<bool> max_find;
		max_find.push(true);
		int max_r[n];
		int max_l[n];
		int min_r[n];
		int min_l[n];
		stack<int> temp;
		// max_l
		int max = -1;
		// cout<<max;
		// = arr[0];
		for(int i=0;i<n;i++){
			max_l[i] = -1;
			if(!(max == -1 or arr[max]<=arr[i])){
				max_l[i]=max;
			}
			// cout<<max<<arr[i];
			if(arr[max]<arr[i] or max == -1){
				max= i;
			}
			// cout<<max_l[i]<<max<<arr[i];
		}
		// while(!temp.empty())
  //   		temp.pop();
		// max_r
		max = -1;
		for(int i=n-1;i>=0;i--){
			max_r[i]  = -1;
			if(!(max == -1 or arr[max]<=arr[i])){
				max_r[i]=max;
			}
			if(arr[max]<arr[i] or max==-1){
				max= i;
			}
			// cout<<max_r[i]<<max<<" ";
		// 	max_r[i] = -1;
		// 	while(!temp.empty() and arr[i]>arr[temp.top()]){
		// 		s.pop();
		// 	}
		// 	if(!temp.empty() and arr[i]<arr[temp.top()]){
		// 		max_r[i] = arr[temp.top()];
		// 	}
		// 	temp.push(i);
		}
		// while(!temp.empty())
  //   		temp.pop();
		// // min_l
		int min = -1;
		for(int i=0;i<n;i++){
			min_l[i] = -1;
			if(!(min==-1 or arr[min]>=arr[i])){
				min_l[i] = min;
			}
			if(arr[min]>arr[i] or min==-1){
				min = i;
			}
		// 	while(!temp.empty() and arr[i]<arr[temp.top()]){
		// 		s.pop();
		// 	}
		// 	if(!temp.empty() and arr[i]>arr[temp.top()]){
		// 		min_l[i] = arr[temp.top()];
		// 	}
		// 	temp.push(i);
		}
		// while(!temp.empty())
  //   		temp.pop();
		// // max_r
		min = -1;
		for(int i=n-1;i>=0;i--){
			min_r[i] = -1;
			if(!(min==-1 or arr[min]>=arr[i])){
				min_r[i] = min;
			}
			if(arr[min]>arr[i] or min==-1){
				min = i;
			}
			// cout<<
		// 	while(!temp.empty() and arr[i]<arr[temp.top()]){
		// 		s.pop();
		// 	}
		// 	if(!temp.empty() and arr[i]>arr[temp.top()]){
		// 		min_r[i] = arr[temp.top()];
		// 	}
		// 	temp.push(i);
		}
		// while(!temp.empty())
  //   		temp.pop();
		while(!s.empty()){
			int ind,a;
			ind = s.top().first;
			a = s.top().second;
			ans.push_back(ind);
			bool inc = max_find.top();
			max_find.pop();
			s.pop();
			// cout<<a<<inc;
			// cout<<max_l[ind]<<max_r[ind]<<min_l[ind]<<min_r[ind]<<a<<inc<<endl;
			if(a==0){
				// both direction
				// left
				if(inc){
					// max
					if(max_l[ind]!=-1){
						// cout<<ind;
						s.push(make_pair(max_l[ind],-1));
						max_find.push(!inc);
					}
				}
				else{
					// min 
					if(min_l[ind]!=-1){
						s.push(make_pair(min_l[ind],-1));
						max_find.push(!inc);
					}
				}
				// right
				if(inc){
					// max
					// cout<<max_r[ind];
					if(max_r[ind]!=-1){
						// cout<<ind;
						s.push(make_pair(max_r[ind],1));
						max_find.push(!inc);
					}
				}
				else{
					// min 
					if(min_r[ind]!=-1){
						s.push(make_pair(min_r[ind],1));
						max_find.push(!inc);
					}
				}
			}
			else if(a==1){

				// right
				if(inc){
					// max
					if(max_r[ind]!=-1){
						s.push(make_pair(max_r[ind],1));
						max_find.push(!inc);
					}
				}
				else{
					// min 
					if(min_r[ind]!=-1){
						s.push(make_pair(min_r[ind],1));
						max_find.push(!inc);
					}
				}
			}
			else{
				// left
				if(inc){
					// max
					if(max_l[ind]!=-1){
						s.push(make_pair(max_l[ind],-1));
						max_find.push(!inc);
					}
				}
				else{
					// min 
					if(min_l[ind]!=-1){
						s.push(make_pair(min_l[ind],-1));
						max_find.push(!inc);
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;	
		for(int i=0;i<ans.size();i++){
			cout<<arr[ans[i]]<<" ";
		}
		cout<<endl;
	}
}