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

// bool seq[100002][100002];
	
int main(){
	int t;cin>>t;
	// t = 2*t;
	for(int q =1;q<=t;q++){
		int n;cin>>n;
		int arr[n];
		int max_n = 0;
		int index = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int min_s = arr[0];
		int min_index = 1;
		int min_pres[n] = {0};
		int max_pres[n] = {0};
		// min_s.push_back(arr[0]);
		// min_pres[0] = false;
		for(int i=1;i<n;i++){
			if(min_s<arr[i]){
				min_pres[i] = min_index;
			}
			if(min_s>arr[i]){
				min_s = arr[i];
				min_index = i+1;
			}
		}
		min_s = arr[n-1];
		min_index = n;
		for(int i = n-2;i>0;i--){
			if(min_s<arr[i]){
				max_pres[i] = min_index;
			}
			if(min_s>arr[i]){
				min_s = arr[i];
				min_index = i+1;
			}
		}
		bool done = false;
		for(int i=1;i<n-1;i++){
			if(min_pres[i]!=0 and max_pres[i]!=0){
				cout<<"YES"<<endl;
				cout<<min_pres[i]<<" "<<i+1<<" "<<max_pres[i]<<endl;
				done = true;
				break;
			}
		}
		// int min_start = INT_MAX,min_end = INT_MAX;
		if(!done)
			cout<<"NO"<<endl;
	}
}