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
	for(int q = 1;q<=t;q++){
		int n;cin>>n;
		bool in[n] = {false},out[n]={false};
		for(int i=0;i<n;i++){
			char o;cin>>o;
			if(o=='N')
				in[i] = false;
			else
				in[i] = true;
		}
		for(int i=0;i<n;i++){
			char o;cin>>o;
			if(o=='N')
				out[i] = false;
			else
				out[i] = true;;
		}
		bool ans[n][n] = {false};
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				ans[i][j]= false;
			}
		}
		// bool ans[n][n] = {false};
		for(int i=0;i<n;i++){
			// change[i][i] = true;
			ans[i][i] = true;
			if(i>0 and in[i-1] and out[i]){
				ans[i][i-1] = true;
			}
			if(i<n-1 and in[i+1] and out[i]){
				ans[i][i+1] = true;
			}
		}
		// lower diag
		for(int i=2;i<n;i++){
			for(int j=i-2;j>=0;j--){
				if(ans[i-1][j] and ans[i][j+1]){
					ans[i][j] = true;
				}
			}
		}
		// upper diag
		for(int i=n-1;i>=0;i--){
			for(int j=2+i;j<n;j++){
				if(ans[i][j-1] and ans[i+1][j]){
					ans[i][j] = true;
				}
			}
		}	
		// output:
		cout<<"CASE #"<<q<<":"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]){
					cout<<"Y";
				}
				else{
					cout<<"N";
				}
			}
			cout<<endl;
		}
	}
}