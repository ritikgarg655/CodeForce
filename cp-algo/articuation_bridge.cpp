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

int tin[1001],low[1001];
// vector<int> i
int timec;
void dfs(vector<int> graph[],int n,bool visited[],int v,int p = -1){
	tin[v] = low[v] = timec++;
	visited[v] = true;
	for(int i=0;i<graph[v].size();i++){
		if(graph[v][i]==p) continue;
		else if(visited[graph[v][i]]){
			low[v] = min(low[graph[v][i]],low[v]);
		}
		else{
			dfs(graph,n,visited,graph[v][i],v);
			low[v] = min(low[v],low[graph[v][i]]);
			if(low[v] < low[graph[v][i]]){
				cout<<v+1<<" "<<graph[v][i]+1<<endl;
			}
		}
	}
}

int main(){
	int n,m;cin>>n>>m;
	vector<int> graph[n];
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bool visited[n] = {false};
	dfs(graph,n,visited,0);
}