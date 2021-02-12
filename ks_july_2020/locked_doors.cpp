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

// bool seq[100002][100002];
	
int main(){
	int t;cin>>t;
	for(int q =1;q<=t;q++){
		int n,qe;cin>>n>>qe;
		int arr[n-1];
		for(int i=0;i<n-1;i++){
			cin>>arr[i];
		}
		// cout<<"a";
		// for(int i=0;i<n;i++){
		// 	int start_room  = i;
		// 	int end_room = i;
		// 	seq[i][0] = i;
		// 	for(int j = 1;j<n;j++){
		// 		if(start_room==0){
		// 			end_room++;
		// 			seq[include][j] = end_room;
		// 		}
		// 		else if(end_room == n-1){
		// 			start_room--;
		// 			seq[i][j] = start_room;
		// 		}
		// 		else{
		// 			if(arr[end_room]>arr[start_room-1]){
		// 				start_room--;
		// 				seq[i][j] = start_room;
		// 			}
		// 			else{
		// 				end_room++;
		// 				seq[i][j] = end_room;
		// 			}
		// 		}
		// 	}
		// }
		cout<<"Case #"<<q<<": ";
		for (int i = 0; i < qe; ++i)
		{
			int s,k;
			cin>>s>>k;
			int start_room  = s-1;
			int end_room = s-1;
			int seq[k];
			seq[0] = s-1;
			for(int j = 1;j<k;j++){
				if(start_room==0){
					end_room++;
					seq[j] = end_room;
				}
				else if(end_room == n-1){
					start_room--;
					seq[j] = start_room;
				}
				else if(arr[end_room]>arr[start_room-1]){
					start_room--;
					seq[j] = start_room;
				}
				else{
					end_room++;
					seq[j] = end_room;
				}
			}
			cout<<" "<<seq[k-1]+1;
		}
		cout<<endl;
	}
}