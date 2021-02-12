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
		int n;cin>>n;
		int num_8 = 0;
		int num_2 = 0;
		int num_1 = 0;
		int temp_n = n;
		num_8 = temp_n/4;
		temp_n%=4;
		// num_2 = temp_n/2;
		// temp_n%=2;
		if(temp_n>0){
			num_8++;// = 1;
		}
		for(int i=0;i<n-num_8 -num_1-num_2 ; i++ ){
			cout<<"9";
		}
		// for(int i=0;i<num_1;i++){
		// 	cout<<"1";
		// }
		// for(int i=0;i<num_2;i++){
		// 	cout<<"2";
		// }
		for(int i=0;i<num_8;i++){
			cout<<"8";
		}
		cout<<endl;
	}
}