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
		vector<int> count;
		char start = s[0];
		int temp_count = 0;
		for(int i=0;i<s.length();i++){
			if(start==s[i]){
				temp_count++;
			}
			else{
				// cout<<
				count.push_back(temp_count);
				temp_count = 1;
				start = s[i];
			}
		}
		count.push_back(temp_count);
		int num_chances = -1;
		if(count.size()>1)
		for(int i=0;i<count.size()-1;i++){
			if(count[i]==count[i+1]){
				num_chances+=count[i];
				count[i+1] = 0;
			}
			else if(count[i]>count[i+1]){
				count[i] -= count[i+1];
				num_chances += count[i+1];
				count[i+1] = 0;
				if(i!=count.size()-2){
					count[i+2] += count[i];
				}
			}
			else{
				count[i+1] -= count[i];
				num_chances += count[i];
				count[i] = 0;
			}
		}
		if(num_chances%2==0){
			cout<<"DA"<<endl;
		}
		else{
			cout<<"NET"<<endl;
		}
	}
}