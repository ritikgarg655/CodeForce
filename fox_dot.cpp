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

char arr[51][51];
bool visited[51][51];
bool dfs(char val,int row,int col,int n,int m,int parent_row,int parent_col){
	// cout<<col<<row<<endl;
	if(visited[row][col] and arr[row][col]==val){
		// cout<<row<<col<<parent_col;
		return true;
	}
	if(arr[row][col]==val){
		// cout<<row<<col<<parent_col<<parent_row<<endl;
		visited[row][col] = true;
		if(col!=m-1 and parent_col!=col+1){
			// cout<<parent_col<<col;
			if(dfs(val,row,col+1,n,m,row,col)){
				// cout<<row<<col+1<<0<<endl;
				return true;
			}
		}
		if(row!=n-1 and parent_row!=row+1){
			if(dfs(val,row+1,col,n,m,row,col)){
				// cout<<row+1<<col<<-1<<endl;
				return true;
			}
		}
		if(row!=0 and parent_row!=row-1 ){
			if(dfs(val,row-1,col,n,m,row,col)){
				// cout<<row-1<<col<<-2<<endl;
				return true;
			}
		}
		if(col!=0 and parent_col!=col-1){
			if(dfs(val,row,col-1,n,m,row,col)){
				// cout<<row<<col-1<<parent_col<<-3<<endl;
				return true;
			}
		}
	}
	else{
		return false;
	}
	return false;
}

int main(){
	int n,m;cin>>n>>m;
	set<char> uniq;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			uniq.insert(arr[i][j]);
		}
	}
	for(auto it=uniq.begin();it!=uniq.end();it++){
		for(int j=0;j<51;j++){
			for(int k=0;k<51;k++){
				visited[j][k] = false;
			}
		}
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(!visited[j][k])
				if(dfs(*it,j,k,n,m,-1,-1)){
					cout<<"Yes"<<endl;
					// cout<<j<<k;
					return 0;
				}
			}
		}	
	}
	cout<<"No"<<endl;
}