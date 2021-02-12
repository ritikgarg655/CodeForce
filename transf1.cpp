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
	int t;cin>>t;while(t--){
		int n;cin>>n;
		string t_a,t_b,a,b;cin>>t_a;
		cin>>t_b;
		vector<pair<char,char>> temp_s;
		for(int i=0;i<n;i++){
			temp_s.push_back(make_pair(t_b[i],t_a[i]));
		}
		sort(temp_s.begin(),temp_s.end());
		a = "";
		b = "";
		for(int i=0;i<n;i++){
			b+=temp_s[i].first;
			a+=temp_s[i].second;
		}
		// cout<<a<<b;
		bool freq[20][20] = {false};
		bool ans = true;
		int num_ans = 0;
		bool pres[20][20] = {false};
		for(int i=0;i<n;i++){
			pres[(int)(a[i]-'a')][(int)(b[i]-'a')] = true;
		}
		bool conv[20] = {false};
		for(int i=0;i<n;i++){
			if(a[i]>b[i]){
				ans = false;
				break;
			}
			else if(a[i]<b[i]){
				char temp = a[i];
				bool temp_done = false;
				for(int j=(int)(a[i]-'a')+1;j<20;j++){
					if(pres[(int)(a[i]-'a')][j] and pres[j][(int)(b[i]-'a')] and (int)(b[i]-'a')!=j){
						temp_done = true;
						break;
					}
				}
				if(temp_done){
					// bool t = false;
					// for(int j = temp_done;j<20;j++){
					// 	if(pres[j][(int)(b[i]-'a')]){
					// 		t = true;
					// 		break;
					// 	} 	
					// }
					// if(t){
						continue;
					// }
				}
				freq[(int)(b[i]-'a')][(int)(a[i]-'a')] = true;
				conv[(int)(b[i]-'a')] = true;
			}
		}
		if(!ans){
			cout<<-1<<endl;
		}
		else{
			for(int i=0;i<20;i++){
				for(int j=0;j<20;j++){
					if(freq[i][j]){
						num_ans++;
					}
				}
			}
			cout<<num_ans<<endl;
		}
	}
}