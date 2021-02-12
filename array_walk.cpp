#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

int main(){
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		long long int n,k,z;cin>>n>>k>>z;
		long long int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		long long int sum = 0LL;
		if(z==0){

			for(int i=0;i<k+1;i++){
				sum += arr[i];
			}
			cout<<sum<<endl;
			continue;
		}
		long long int dp[n][z+1] = {0};
		for(int i=0;i<k+1;i++){
			if(i==0){
				dp[0][0] = arr[i];
				for(int j=0;j<z;j++){
					dp[0][j+1] = 0;
				}
				continue;
			}
			
			dp[i][0] = dp[i-1][0] + arr[i];
			for(int j=1;j<(z+1);j++){
				if(dp[i-1][j]!=0)
					dp[i][j] = dp[i-1][j]+arr[i];
				// int rem_k = 0;
				// if(dp[i-1][j]!=0){
				// 	rem_k = k+1+ (i+(2*j));
				// }
				// int temp = dp[i-1][j]+arr[i];
				// if(rem_k>0 and dp[i][j]<temp){
				// 	dp[i][j] = dp[i-1][j]+arr[i];
				// }
				// else if(rem_k==0 and dp[i][j]<temp)
			}
			for(int j=1;j<z+1;j++){
				if(dp[i-1][j-1]!=0){
					int temp = dp[i-1][j-1];
					temp += arr[i-1] + arr[i];
					int rem_k =  k+1 - (i  + (2*j));
					if(dp[i][j]<temp + arr[i] and rem_k>1){
						dp[i][j] = temp + arr[i];
					}
					else if(dp[i][j]<temp and rem_k>0){
						dp[i][j] =  temp;
						if(sum<temp){
							sum = temp;
						}
					}
					// if(dp[i][j+1]==0){
					// 	continue;
					// }
					// temp = dp[i][j-2] + arr[i-1];
					// rem_k -= 2;
					// if(i>1 and j<z-1 and rem_k>=3){
					// 	temp += arr[i-2];
					// 	if(dp[i][j+1]<temp + arr[i-1]  + arr[i]) {
					// 		dp[i][j+1] = temp+ arr[i-1]  + arr[i];
					// 	}
					// }
					// else if(i>1 and j<z-1 and rem_k>=2){
					// 	temp += arr[i-2];
					// 	if(dp[i][j+1]<temp + arr[i-1]) {
					// 		dp[i][j+1] = temp+ arr[i-1];
					// 	}
					// 	if(sum<temp + arr[i-1]){
					// 		sum = temp + arr[i-1];
					// 	}
					// }
					// else if(i>1 and j<z-1 and rem_k>=1){
					// 	temp += arr[i-2];
					// 	if(dp[i][j+1]<temp ) {
					// 		dp[i][j+1] = temp;
					// 	}
					// 	if(sum<temp){
					// 		sum = temp;
					// 	}
					// }
				}
			}
			for(int j=0;j<z+1;j++){
				int temp_k = k -  (i + (2*j));
				if(sum<dp[i][j] and temp_k>=0){
					sum = dp[i][j];
				}
			}
		}
		// for(int i=0;i<k+1;i++){
		// 	for(int j=0;j<z+1;j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cout<<sum<<endl;
	}
}