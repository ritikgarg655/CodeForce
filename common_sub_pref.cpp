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
	int t;cin>>t;while(t--){
		int n;cin>>n;
		int arr[n];
		string ans[n+1];
		for(int i=0;i<51;i++){
			ans[0]+='a';
		}
		// for(int i=0;i<n;i++){
		// 	ans[i+1] = ans[i];
		// }
		for(int i=0;i<n;i++){
			cin>>arr[i];
			ans[i+1] = ans[i];
			if(ans[i+1][arr[i]]=='z'){
				ans[i+1][arr[i]] = 'a';	
			}
			else{
				ans[i+1][arr[i]]++;// = ans[i+1][arr[i]]+1;
			}
		}
		for(int i=0;i<n+1;i++){
			cout<<ans[i]<<endl;
		}
	}
}