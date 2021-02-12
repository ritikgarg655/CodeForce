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
		if(n>30 ){
			cout<<"YES"<<endl;
			if(n-30 == 14){
				cout<<"6 10 15 "<<n-31<<endl;
			}
			else if(n-30 == 10){
				cout<<"6 14 15 "<<n-35<<endl;
			}
			else if(n-30 == 6){
				cout<<"6 10 15 "<<n-31<<endl;
			}
			else
			cout<<"6 10 14 "<<n-30<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}