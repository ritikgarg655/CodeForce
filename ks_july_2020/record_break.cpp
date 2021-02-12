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
	for(int q =1;q<=t;q++){
		int n;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		bool inc = true;
		int temp_max = -1;
		int ans = 0;
		for(int i=1;i<n;i++){
			if(arr[i-1]>arr[i]){
				// ans++;
				if(temp_max<arr[i-1]){
					temp_max = arr[i-1];
					ans++;
				}
			}
		}
		if(temp_max<arr[n-1] ){
			if(n>1 and arr[n-1]>arr[n-2]){
				ans++;
			}
			else if(n==1){
				ans++;
			}
		}
		cout<<"Case #"<<q<<": ";
		cout<<ans<<endl;
	}
}