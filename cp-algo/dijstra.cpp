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


struct comp { 
    template<class T1,class T2,class T3,class T4>
    bool operator()(const pair<T1,T2> &p1,const pair<T3,T4> &p2){
        if(p1.first!=p2.first)return p1.first>p2.first;
        else return p1.second<p2.second;
    }
}; 
 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n,m;cin>>n>>m;
	vector<vector<pair<int,int>>> graph(n);
	for(int i=0;i<m;i++){
		int a,b,w;cin>>a>>b>>w;
		a--;b--;
		graph[a].push_back({b,w});
		graph[b].push_back({a,w});
	}
	// dijkstra
	vector<int>  p(n+1,0);//] = {0};
	priority_queue<pair<int,int>,vector<pair<int,int>>, comp> dist;
	vector<int> d(n,INT_MAX);
	// fill(d,d+n,INT_MAX);
	dist.push({0,0});
	d[0] = 0;
	while(!dist.empty()){
		int v = dist.top().second;
		int w = dist.top().first;
		// finding small dist vertex
		dist.pop();
		if(d[v] == INT_MAX ){
			break;
		}
		for(int j=0;j<graph[v].size();j++){
			if(d[graph[v][j].first] > w + graph[v][j].second){
				d[graph[v][j].first] = w + graph[v][j].second;
				p[graph[v][j].first+1] = v+1;
				dist.push({d[graph[v][j].first],graph[v][j].first});
			}
		}
		graph[v].clear();
	}
	if(d[n-1]==INT_MAX){
		cout<<-1<<endl;
		return 0;
	}
	int vert = n;
	vector<int> ans_seq;
	while(vert!=0){
		ans_seq.push_back(vert);
		vert = p[vert];
		// cout 
	}
	for (int i = ans_seq.size()-1; i >=0; i--)
	{
		cout<<ans_seq[i]<<" ";
	}
	cout<<endl;
}