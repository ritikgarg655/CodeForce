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
	cin>>t;
	// t = 1;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n];
		int b[m];
		bool present[1001] = {false};
		for(int i=0;i<n;i++){
			cin>>a[i];
			present[a[i]] = true;
		}
		bool done = false;
		int val;
		for(int j=0;j<m;j++){
			cin>>b[j];
			if(present[b[j]] and !done){
				done = true;
				val = b[j];
			}
		}
		if(done){
			cout<<"YES"<<"\n1 "<<val<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}