#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;int arr[n];
	int min_a = INT_MAX;
	int max_a = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(max_a<arr[i]){
			max_a = arr[i];
		}
		if(min_a>arr[i]){
			min_a =arr[i];
		}
	}
	int m;cin>>m;int b[m];
	int min_b = INT_MAX;
	int max_b = 0;
	for(int i=0;i<m;i++){
		cin>>b[i];
		if(max_b<b[i]){
			max_b = b[i];
		}
		if(min_b>b[i]){
			min_b =b[i];
		}
	}
	int ans_a = 0;
	int ans_b = 0;
	sort(arr,arr+n);
	sort(b,b+m);
	int freq[n];
	queue<int> q;
	for(int j=0;j<m;j++){
		if(b[j]>=arr[0]){
			// cout<<b[j];
			q.push(b[j]);
		}
	}
	// freq[0] = q.size();
	for(int i=0;i<n;i++){
		freq[i] = 0;
		while(!q.empty() and q.front()<arr[i]){
			// cout<<q.front()<<arr[i];
			q.pop();
		}
		if(!q.empty()){
			freq[i] = (int)q.size();
		}
		// cout<<q.front()<<endl;
	}
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		int temp_ans = 0;
		temp_ans = (n-i)*3 + i*2;
		temp_ans  -= ((m-freq[i])*2 + freq[i]*3);
		// cout<<temp_ans;
		if(temp_ans>ans){
			ans = temp_ans;
			ans_a = (n-i)*3 + i*2;
			ans_b = (m-freq[i])*2 + freq[i]*3;
		}
		else  if(temp_ans==ans and ans_a<((n-i)*3 + i*2)){
			ans = temp_ans;
			ans_a = (n-i)*3 + i*2;
			ans_b = (m-freq[i])*2 + freq[i]*3;			
		}
	}
	if(ans<(n*2 - m*2)){
		ans_a = n*2;
		ans_b = m*2;
	}
	cout<<ans_a<<":"<<ans_b;
	// if(max_b<min_a){
	// 	ans_a = n*3;
	// 	ans_b = m*2;
	// }
	// else if(min_b<min_a and max_b>min_a and max_b<=max_a){
	// 	int num = 0;
	// 	for(int i=0;i<m;i++){
	// 		if(b[i]>=min_a){
	// 			num++;
	// 		}
	// 	}
	// 	if(num>n){
	// 		ans_a = n*2;
	// 		ans_b = m*2;
	// 	}
	// 	else{
	// 		ans_a = n*3;
	// 		ans_b = num*3 + (m*num)*2;
	// 	}
	// }
	// else if(min_a>min_b){

	// }
}