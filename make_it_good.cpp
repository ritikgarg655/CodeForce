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
// An interval has a start time and end time 
// struct Interval 
// { 
//     int start, end; 
// };
// bool compareInterval(Interval i1, Interval i2) 
// { 
//     return (i1.start < i2.start); 
// } 
int main(){
	int t;cin>>t;while(t--){
		int n;cin>>n;
		int array[n];
		queue<int> q;
		stack<int> s;
		for(int i=0;i<n;i++){
			cin>>array[i];
			q.push(array[i]);
		}
		for(int i=n-1;i>=0;i--){
			s.push(array[i]);
		}
		int ans = 0;
		int start_ind = 0;
		int max_done = INT_MAX;
		for(int i=0;i<n;i++){
			// cout<<max_done<<endl;
			
			if(s.top()>max_done){
				break;
			}
			else if(s.top()<=q.front() and !s.empty()){
				max_done = s.top();
				s.pop();
			}
			else if(s.top()>=q.front() and q.front()>=max_done and !q.empty()){
				max_done = q.front();
				q.pop();
				start_ind++;
			}
			else
			while(q.front()<max_done and !q.empty()){
				q.pop();
				start_ind++;
				ans = start_ind;
				i++;
			}
		}
		cout<<ans<<endl;
	}
}


		// vector<pair<int,int>> arr;int min_v = INT_MAX;
		// for(int i=0;i<n;i++){
		// 	int a;cin>>a;
		// 	if(a>min_v){
		// 		min_v = a;
		// 	}
		// 	arr.push_back({a,i});
		// }
		// sort(arr.begin(),arr.end());
		// int start = -1;
		// int min_col = INT_MAX;
		// int min_start = 0;
		// int start_ind = 0;
		// int end_ind = n-1;
		// bool cont[n] = {false};
		// int a_cont[n] = {0};
		// for(int i=0;i<n;i++){
		// 	// cout<<min_col<<endl;
		// 	if(cont[start_ind] and arr[start_ind].first == a_cont[start_ind]){
		// 		start_ind++;
		// 		// cout<<i;
		// 	}
		// 	else if(cont[end_ind] and arr[end_ind].first == a_cont[end_ind]){
		// 		end_ind--;
		// 	}
		// 	if( arr[i].first == min_col){
		// 		// cout<<i<<endl;
		// 		cont[arr[i].second] = true;
		// 		a_cont[arr[i].second] = arr[i].first;
		// 	}
		// 	else if(arr[i].second == end_ind ){
		// 		end_ind--;
		// 		min_col = arr[i].first;
		// 		// cout<<i<<endl;
		// 		continue;
		// 	}
		// 	else{
		// 		if(arr[i].second == start_ind or arr[i].first == min_col){
		// 			start_ind++;
		// 			min_col = arr[i].first;
		// 			// cout<<i<<endl;
		// 		}
		// 		else if(arr[i].second > min_start and arr[i].second>start_ind){
		// 			// cout<<start_ind<<endl;
		// 			min_start = arr[i].second;
		// 			start_ind = min_start+1;
		// 			min_col = arr[i].first;
		// 		}
		// 	}
		// }
		// cout<<min_start<<endl;