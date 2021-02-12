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
	int n;cin>>n;
	// cout<<n;
	vector<pair<int,int>> a;
	for(int i=0;i<n;i++){
		// cout<<i;
		int temp1,temp2;
		cin>>temp1>>temp2;
		a.push_back(make_pair(temp1,temp2));
	}
	int k;cin>>k;
	pair<int,int> arr_k[k];
	int max_k = 0;
	for(int i=0;i<k;i++){
		// cout<<k;
		int a;
		cin>>a;
		arr_k[i] = make_pair(a,i);
		if(max_k<a){
			max_k = a;
		}
	}
	// cout<<k;
	vector<pair<int,int>> final_a;
	// cout<<"@";
	for(int i=0;i<n;i++){
		// cout<<i;
		if(a[i].first <=max_k){
			final_a.push_back(make_pair(a[i].second,a[i].first*1001 + i));
		}
	}
	sort(final_a.begin(),final_a.end());
	sort(arr_k,arr_k+k);
	int end_a = final_a.size()-1;
	int start_k = 0;
	int ans = 0;
	long long int sum = 0LL;
	vector<pair<int,int>> ans_k;
	while(end_a>=0){
		start_k = 0;
		while(start_k<k){
			int val = final_a[end_a].second/1001;
			if(arr_k[start_k].first!=-1 and arr_k[start_k].first>=val){
				ans++;
				sum+=final_a[end_a].first;
				arr_k[start_k].first = -1;
				ans_k.push_back(make_pair(final_a[end_a].second%1001,arr_k[start_k].second+1));
				break;
			}
			start_k++;
		}
		end_a--;
	}
	cout<<ans<<" "<<sum<<endl;
	for(int i=0;i<ans;i++){
		cout<<ans_k[i].first+1<<" "<<ans_k[i].second<<endl;
	}
	return 0;
}