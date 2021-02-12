// #ifndef _GLIBCXX_NO_ASSERT
// #include <cassert>
// #endif
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// #include <cwchar>
// #include <cwctype>
 
// #if __cplusplus >= 201103L
// #include <ccomplex>
// #include <cfenv>
// #include <cinttypes>
// #include <cstdalign>
// #include <cstdbool>
// #include <cstdint>
// #include <ctgmath>
// #include <cuchar>
// #endif
 
// // C++
// #include <iostream> 
// #include <algorithm> 
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>
// using namespace std;



// int main(){
// 	int t;cin>>t;while(t--){
// 		long int n;cin>>n;
// 		long int arr[n];
// 		vector<long int> even_odd;
// 		vector<long int> odd_even;
// 		long long int ans = 0LL;
// 		for(int i=0;i<n;i++){
// 			cin>>arr[i];
// 		}
// 		for(int i=0;i<n;i++){
// 			if(i%2==0){
// 				ans += arr[i];
// 				if(i!=0){
// 					odd_even.push_back(-arr[i]+arr[i-1]);
// 				}
// 				if(i!=n-1){
// 					even_odd.push_back(arr[i+1]-arr[i]);
// 					// cout<<arr[i+1]-arr[i]<<endl;
// 				}
// 			}
// 		}
// 		// cout<<even_odd.size();
// 		long int max_even_odd = 0;
// 		long int start_even_odd = -1;
// 		long int end_even_odd = -1;
// 		long int max_odd_even=0;
// 		long int start_odd_even = -1;
// 		long int end_odd_even = -1;
// 		long long int temp_sum = 0LL;
// 		long int temp_start = -1;
// 		for(int i=0;i<odd_even.size();i++){
// 			if(odd_even[i]>0){
// 				temp_sum+=odd_even[i];
// 				if(temp_start == -1){
// 					temp_start = i;
// 				}
// 			}
// 			else if(temp_start!=-1){
// 				if(max_odd_even<temp_sum){
// 					start_odd_even = temp_start;
// 					end_odd_even = i-1;
// 					max_odd_even = temp_sum;
// 					temp_start = -1;
// 					temp_sum = 0;
// 				}
// 			}
// 		}
// 		// cout<<max_odd_even<<endl;
		
// 		if(temp_sum>max_odd_even){
// 			// start_odd_even = temp_start;
// 			end_odd_even = odd_even.size()-1;
// 			start_odd_even = temp_start;
// 			max_odd_even = temp_sum;
// 			if(temp_sum>max_odd_even){
// 				temp_sum = max_odd_even;
// 			}
// 		}
// 		if(start_odd_even!=-1){
// 			temp_sum = max_odd_even;
// 			for(int i = start_odd_even-1;i>=0;i--){
// 				temp_sum += odd_even[i];
// 				if(temp_sum>max_odd_even){
// 					max_odd_even = temp_sum;
// 					start_odd_even = i;
// 				}
// 			}
// 			temp_sum = max_odd_even;
// 			for(int i = end_odd_even+1;i<odd_even.size();i++){
// 				temp_sum += odd_even[i];
// 				if(temp_sum>max_odd_even){
// 					max_odd_even = temp_sum;
// 					end_odd_even = i;
// 				}
// 			}
// 		}
// 		temp_sum = 0LL;
// 		temp_start = -1;
// 		// cout<<max_even_odd<<endl;ssss
// 		for(int i=0;i<even_odd.size();i++){
// 			// cout<<even_odd[i]<<endl;
// 			if(even_odd[i]>0){
// 				temp_sum+=even_odd[i];
// 				// cout<<temp_sum<<endl;
// 				if(temp_start == -1){
// 					// cout<<i;
// 					temp_start = i;
// 				}
// 			}
// 			else if(temp_start!=-1){
// 				// cout<<temp_sum;
// 				if(max_even_odd<temp_sum){
// 					start_even_odd = temp_start;
// 					max_even_odd = temp_sum;
// 					end_even_odd = i-1;
// 					temp_start = -1;
// 					temp_sum = 0;
// 				}
// 			}
// 		}
// 		// cout<<temp_sum;
// 		// cout<<max_even_odd;
// 		// cout<<start_even_odd<<endl;
// 		if(temp_sum>max_even_odd){
// 			max_even_odd = temp_sum;
// 			end_even_odd = even_odd.size()-1;
// 			start_even_odd = temp_start;
// 			if(temp_sum>max_even_odd){
// 				temp_sum = max_even_odd;
// 			}
// 		}
// 		// cout<<start_even_odd<<endl;
// 		// cout<<max_even_odd<<endl;
// 		if(start_even_odd!=-1){
// 			temp_sum = max_even_odd;
// 			for(int i = start_even_odd-1;i>=0;i--){
// 				temp_sum += even_odd[i];
// 				if(temp_sum>max_even_odd){
// 					max_even_odd = temp_sum;
// 					start_even_odd = i;
// 				}
// 			}
// 			temp_sum = max_even_odd;
// 			for(int i = end_even_odd+1;i<even_odd.size();i++){
// 				temp_sum += even_odd[i];
// 				if(temp_sum>max_even_odd){
// 					max_even_odd = temp_sum;
// 					end_even_odd = i;
// 				}
// 			}
// 		}
// 		// cout<<ans;
// 		// cout<<max_even_odd<<max_odd_even<<endl;
// 		ans += max(max_even_odd,max_odd_even);
// 		cout<<ans<<endl;
// 	}
// }
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) cin >> it;
		vector<vector<long long>> dp(n + 1, vector<long long>(3));
		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));
			if (i + 2 <= n) dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));
			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
		}
		cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
	}
	
	return 0;
}