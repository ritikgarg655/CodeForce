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

long long int x,y,z,a,b,c;

// void dfs(int ind = 0){
// 	if(ind==0){
// 		a = 
// 	}
// 	dfs(ind+1);
// }

int main(){
	int t;cin>>t;while(t--){
		cin>>x>>y>>z;
		// dfs();
		// a>b>c 
		if(x==y and x>=z){
			a = x;
			b = z;
			c = 1;
		}
		// b>a>c
		else if(x==z and x>=y){
			b = x;
			a = y;
			c = 1;
		}
		// c>a>b
		else if(y==z and x<=y){
			c = y;
			a = x;
			b = 1;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
		// c>b>a
		cout<<"YES"<<endl;
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
}