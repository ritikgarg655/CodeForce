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

int min_ans;

void dfs(int arr[],int n,int index,int start = -1,int count = 0){
	if(index==n){
		if(count<min_ans){
			min_ans = count;
		}
		return;
	}
	if( start== -1){
		dfs(arr,n,index+1,1,count);
		dfs(arr,n,index+1,2,count);
		dfs(arr,n,index+1,3,count);
		dfs(arr,n,index+1,4,count);
		return;
	}
	if(arr[index-1]<arr[index]){
		for(int i=start+1;i<=4;i++){
			dfs(arr,n,index+1,i,count);
		}
		for(int i=1;i<=start;i++){
			dfs(arr,n,index+1,i,count+1);
		}
	}
	else if(arr[index-1]>arr[index]){
		for(int i=start;i<=4;i++){
			dfs(arr,n,index+1,i,count+1);
		}
		for(int i=1;i<start;i++){
			dfs(arr,n,index+1,i,count);
		}	
	}
	else{
		for(int i=start+1;i<=4;i++){
			dfs(arr,n,index+1,i,count+1);
		}
		for(int i=1;i<start;i++){
			dfs(arr,n,index+1,i,count+1);
		}
		dfs(arr,n,index+1,start,count);
	}
}

int main(){
	int t;cin>>t;
	for(int q =1;q<=t;q++){
		min_ans = INT_MAX;
		int n;cin>>n;int arr[n];
		vector<int> inc_data;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<int> same;
		
		dfs(arr,n,0);

		cout<<"Case #"<<q<<": "<<min_ans<<endl;
	}
}