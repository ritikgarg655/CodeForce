#include<bits/stdc++.h>
using namespace std;

void find_prime_list(vector<int> &list_prime_num,int max_limit,int index){
	if(index>max_limit) return;
	bool done = true;
	// cout<<index<<endl;
	for(int i=0;i<list_prime_num.size();i++){
		if(index%list_prime_num[i] == 0){done = false;break;}
	}
	if(done) list_prime_num.push_back(index);
	find_prime_list(list_prime_num,max_limit,index+2);
}

int main(){
	int n;cin>>n;
	vector<int> list_prime_num;
	int max_limit = 10000;
	list_prime_num.push_back(2);
	list_prime_num.push_back(3);
	list_prime_num.push_back(5);
	list_prime_num.push_back(7);
	find_prime_list(list_prime_num,max_limit,9);
	int m = 1;
	while(1){
		int cur_num = n*m + 1;
		if(find(list_prime_num.begin(),list_prime_num.end(),cur_num)==list_prime_num.end()){
			break;
		}	
		m++;
	}
	cout<<m<<endl;
}