// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++){
// 		cin>>arr[i];
// 		// cout<<arr[i];
// 	}
// 	int ans = 0;
// 	int start = 0;
// 	int end = 0;
// 	int max = 0;
// 	for(int i=0;i<n;i++){
// 		int sum = 0;
// 		int temp_start = i;
// 		int temp_end = 0;
// 		int temp_max = 0;
// 		bool pos = false;
// 		while(arr[i]>0 and i<n){
// 			sum += arr[i];
// 			pos = true;
// 			// cout<<arr[i];
// 			if(arr[i]>temp_max){
// 				// cout<<arr[i];
// 				temp_max = arr[i];
// 			}
// 			i++;
// 		}
// 		// cout<<temp_max<<endl;
// 		temp_end = i-1;
// 		if(ans<=(sum-temp_max) and pos){
// 			ans = sum - temp_max;
// 			start = temp_start;
// 			end = temp_end;
// 			max = temp_max;
// 		}
// 	}
// 	// cout<<max;
// 	int temp_ans = ans + max;
// 	int temp_max = max;
// 	// cout<<temp_ans;
// 	for(int i = end+1;i<n;i++){
// 		temp_ans += arr[i];
// 		// cout<<temp_ans;
// 		if(temp_max<arr[i]){
// 			temp_max = arr[i];
// 		}
// 		if(ans<(temp_ans- temp_max)){
// 			// cout<<temp_ans;
// 			ans = temp_ans - temp_max;
// 			max= temp_max;
// 		}
// 	}
// 	temp_ans = ans + max;
// 	temp_max = max;
// 	for(int i = start-1;i>=0;i--){
// 		temp_ans += arr[i];
// 		if(temp_max<arr[i]){
// 			temp_max = arr[i];
// 		}
// 		if(ans<(temp_ans- temp_max)){
// 			// cout<<temp_max;
// 			ans = temp_ans - temp_max;
// 			max= temp_max;
// 		}
// 	}
// 	// cout<<max;
// 	cout<<ans<<endl;
// }			
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
const int INF = 1e9;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	long long ans = 0;
	forn(mx, 31){
		long long cur = 0;
		long long best = 0;
		forn(i, n){
			int val = (a[i] > mx ? -INF : a[i]);
			cur += val;
			best = min(best, cur);
			ans = max(ans, (cur - best) - mx);
		}
	}
	printf("%lld\n", ans);
	return 0;
}