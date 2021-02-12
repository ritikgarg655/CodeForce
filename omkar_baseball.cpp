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
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		long long int ans = 0LL;
		long long int eq = 0LL;
		bool start = true,end = true;
		int start_index = 0,end_index = n-1;
		int all_eq = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i]==i+1){
				all_eq++;
				if(i==start_index and start){
					start_index++;
					continue;
				}
				start = false;
				eq++;
			}
		}
		int temp = 0;
		for(int i=n-1;i>=0;i--){
			if(arr[i]==i+1 and end){
				// end_index--;
				temp++;
			}	
			else{
				end = false;
				break;
			}
		}
		eq -= temp;
		if(all_eq==n){
			cout<<0<<endl;
		}
		else{
			if(eq==0){
				cout<<1<<endl;
			}
			else{
				cout<<2<<endl;
			}
		}
	}
}