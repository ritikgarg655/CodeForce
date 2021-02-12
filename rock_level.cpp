#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr_e[n];
		for(int i=0;i<n;i++){
			cin>>arr_e[i];
		}
		long long int ans_e = 0LL;
		map<int,int> m_e;
		for(int i=0;i<n;i++){
			int crr_e = (int)(log2(arr_e[i]));
			if(m_e.find(crr_e)!=m_e.end()){
				ans_e+=m_e[crr_e];
			}
			m_e[crr_e]++;
		}
		cout<<ans_e<<endl;
	}
}