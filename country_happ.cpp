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
	int t;
	// t = 1;
	cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		int a[n],h[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			// cout<<a[i];
		}
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		vector<int> g[n];
		for(int i=0;i<n-1;i++){
			int q,w;cin>>q>>w;
			q--;w--;
			g[q].push_back(w);
			g[w].push_back(q);
		}
		// finding shortest path
		int v[n] = {0}; // visited people each country
		// bfs for shortest distance
		queue<int> q,per;
		q.push(0);
		// cout<<q.front()<<" sw";
		bool visited[n] = {false};
		int parent[n] ;
		for(int i=0;i<n;i++){
			parent[i] = -1;
			v[i] = 0;
		}
		// parent
		stack<int> s;
		while(!q.empty()){
			int node = q.front();
			per.push(node);
			// cout<<node<<endl;
			q.pop();
			s.push(node);
			visited[node] = true;
			for(int i=0;i<g[node].size();i++){
				if(!visited[g[node][i]]){
					q.push(g[node][i]);
					parent[g[node][i]] = node;
				}
			}
		}
		while(!s.empty()){
			int node = s.top();
			// cout<<a[node]<<node<<endl;
			s.pop();
			v[node] += a[node];

			if(node!=0){
				v[parent[node]] += v[node];
				// cout<<v[parent[node]]<<endl;
			}
		}
		// for(int i=0;i<n;i++){
		// 	cout<<v[i]<<endl;
		// }
		int prev_bad = 0;
		int prev_good = m;
		bool done = true;
		int track_bad[n] = {0};
		while(!per.empty()){
			int node = per.front();
			per.pop();
			int temp_bad  = 0, temp_good = 0;
			if((v[node]-abs(h[node]))%2!=0 or v[node]<abs(h[node])){
				done = false;
				// cout<<node<<endl;
				break;
			}
			if(h[node]<0){
				temp_bad += abs(h[node]);
				temp_good = (v[node]-abs(h[node]))/2;
				temp_bad += temp_good;
			} 
			else{
				temp_good += h[node];
				temp_bad = (v[node]-h[node])/2;
				temp_good += temp_bad; 
			}
			if(temp_bad + temp_good>v[node]){
				done = false;
				// cout<<node<<"1"<<endl;
				break;
			}
			track_bad[node] = temp_bad;
			// if(node!=0){
			// 	if(min(track_bad[parent[node]],v[node])>temp_bad and v[node]!=0){
			// 		cout<<track_bad[parent[node]]<<v[node]<<" "<<temp_bad<<endl;
			// 		done = false;
			// 		cout<<node<<"2"<<endl;
			// 		break;
			// 	}
			// }
		}
		if(done){
			cout<<"YES"<<endl;

		}
		else{
			cout<<"NO"<<endl;
		}
	}
}	