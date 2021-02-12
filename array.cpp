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
	int n,k;cin>>n>>k;
	vector<int> arr;
	int start = 1;
	set<int> uniq;
	bool done  = false;
	int end = 1;
	bool start_end = false;
	for(int i=0;i<n;i++){
		// if(arr[0])
		int a;cin>>a;
		arr.push_back(a);
		if(arr[0]==a and !start_end){
			start = i+1;
		}
		if(arr[0]!=a)
			start_end = true;
		uniq.insert(a);
		if(uniq.size()==k and !done){
			done = true;
			end = i+1;
		}
	}
	for(int i=start-1;i<=end-1;i++){
		if(std::find(arr.begin()+i+1,arr.begin()+end,arr[i])!=arr.begin()+end){
			start++;
		}
		else{
			break;
		}
	}
	if(done){
		cout<<start<<" "<<end<<endl;
	}
	else{
		cout<<"-1 -1"<<endl;
	}
}