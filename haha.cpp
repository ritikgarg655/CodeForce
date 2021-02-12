#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))



void solve(){
	int i,j,k,q,l;
	int n;
	// n = 1;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	bool done = false;
	for(int i=0;i<=pow(2,n);i++){
		int temp = i;
		vector<int> post;
		int num_1 = 0;
		int index = 0;
		while(temp>0){
			if(temp%2==1){
				num_1++;
				post.push_back(index);
			}
			temp/=2;
			index++;
		}
		if(!(num_1<=n/2 and num_1%2==0)){
			continue;
		}
		int even_sum = 0;
		int odd_sum = 0;
		std::vector<int> ans;
		int index_min = 0;
		for(int j=0;j<n;j++){
			if(!post.empty() and post[0]==j){
				index_min++;
				post.erase(post.begin());
				continue;
			}
			if(((j - index_min)%2)==0 and arr[j]==1){
				even_sum++;
			}
			else if(((j - index_min)%2)==1 and arr[j]==1){
				odd_sum++;
			}
			ans.push_back(arr[j]);
		}
		if(even_sum==odd_sum){
			done = true;
			cout<<ans.size()<<endl;
			for(int j=0;j<ans.size();j++){
				cout<<ans[j]<<" ";
			}
			break;
		}
	}
	if(!done){
		cout<<"1 \n0";
	}
	// int index = 0;
	// while(sum_even!=sum_odd){
	// 	if(arr[index]==arr[index+1]){

	// 	}
	// }
	// if(sum_odd==sum_even){
	// 	cout<<n<<endl;
	// 	for(int i=0;i<n;i++){
	// 		cout<<arr[i]<<" ";
	// 	}
	// }
	// else{
	// 	if(abs(sum_even-sum_even)==n/2){
	// 		cout<<n/2<<endl;
	// 		for(int i=0;i<n/2;i++){
	// 			cout<<"0 ";
	// 		}
	// 	}
	// 	else if(abs(sum_even - sum_odd)*2<=n/2){
	// 		cout<<n-abs(sum_even - sum_odd)<<endl;
	// 		if(sum_odd>sum_even){
	// 			for(int i=0;i<n;i++){
	// 				if(pair_un.front()==i and arr[i]==1){
	// 					i++;
	// 					continue;
	// 				}
	// 				else{
	// 					cout<<arr[i]<<" ";
	// 				}
	// 			}
	// 		}
	// 		else{
	// 			for(int i=0;i<n;i++){
	// 				if(pair_un.front()==i and arr[i-1]==1){
	// 					i++;
	// 					continue;
	// 				}
	// 				else{
	// 					cout<<arr[i]<<" ";
	// 				}
	// 			}
	// 		}
	// 	}
	// 	else{
	// 		int a = abs(sum_even - sum_odd);
	// 		cout<<n-(a%2==0?a:a+1)<<endl;
	// 		if(a%2==0){
	// 			if(sum_odd>sum_even){
	// 				for(int i=0;i<n;i++){
	// 					if(pair_un.front()==i and arr[i]==0){
	// 						cout<<"1 ";
	// 						i++;
	// 						continue;
	// 					}
	// 					else{
	// 						cout<<arr[i]<<" ";
	// 					}
	// 				}
	// 			}
	// 			else{
	// 				for(int i=0;i<n;i++){
	// 					if(pair_un.front()==i and arr[i-1]==0){
	// 						i++;
	// 						cout<<"1 ";
	// 						continue;
	// 					}
	// 					else{
	// 						cout<<arr[i]<<" ";
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}