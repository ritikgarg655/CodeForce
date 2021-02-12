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
#include <iostream> 
#include <algorithm> 
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
	string s;cin>>s;
	if(s.length()==1){
		if(stoi(s)%8==0){
			cout<<"YES"<<endl;
			cout<<s;
			return 0;
		}
		cout<<"NO"<<endl;
		return 0;
	}
	else if(s.length()==2){
		if(stoi(s)%8==0){
			cout<<"YES"<<endl;
			cout<<s<<endl;
		}
		else if(((int)(s[0]-'0'))%8==0){
			cout<<"YES"<<endl;cout<<s[0]<<endl;
		}
		else if(((int)(s[1]-'0'))%8==0){
			cout<<"YES"<<endl;
			cout<<(s[1])<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	else{
		for(int i=0;i<s.length()-2;i++){
			for(int j=i+1;j<s.length()-1;j++){
				for(int k=j+1;k<s.length();k++){
					// cout<<(char)s[i]<<s[j]<<s[k]<<endl;
					int temp1 = (s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
					int temp2 = (s[i]-'0')*10+(s[j]-'0');
					int temp3 = (s[i]-'0')*10+(s[k]-'0');
					int temp4 = (s[j]-'0')*10+(s[k]-'0');
					int temp5 = s[j]-'0';
					int temp6 = s[i]-'0';
					int temp7 = s[k]-'0';
					// cout<<temp<<endl;
					if((temp1)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp1<<endl;
						return 0;
					}
					if((temp2)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp2<<endl;
						return 0;
					}
					if((temp3)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp3<<endl;
						return 0;
					}
					if((temp4)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp4<<endl;
						return 0;
					}
					if((temp5)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp5<<endl;
						return 0;
					}
					if((temp6)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp6<<endl;
						return 0;
					}
					if((temp7)%8==0){
						// cout<<i<<j<<k;
						cout<<"YES"<<endl;
						cout<<temp7<<endl;
						return 0;
					}
				}
			}
		}
		cout<<"NO"<<endl;
	}
}