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
#include <iostream> 
#include <algorithm> 
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
	int t;cin>>t;while(t--){
		string s;cin>>s;
		long int prefix_sum[s.length()] = {0};
		vector<long long int> min_count;
		long int minm = 0;
		for(long int i=0;i<s.length();i++){
			if(i!=0)
				if(s[i]=='-'){
					prefix_sum[i] = prefix_sum[i-1] -1;
				}
				else{
					prefix_sum[i] = prefix_sum[i-1] + 1;
				}
			else{
				if(s[i]=='-'){
					prefix_sum[i] = -1;
				}
				else{
					prefix_sum[i] = 1;
				}
			}
			if(prefix_sum[i]<minm){
				// cout<<i<<minm<<endl;
				min_count.push_back(i+1);
				minm--;
			}
		}
		long int req_it = abs(minm);
		if(req_it==0){
			cout<<s.length()<<endl;
		}
		else{
			long long int ans = 0;
			for(int i=0;i<min_count.size();i++){
				ans += min_count[i];
			}
			ans += s.length();
			cout<<ans<<endl;
		}
	}
}