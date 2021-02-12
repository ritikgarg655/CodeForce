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

int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = 0; i <len; i++) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 


int main(){
	int t;
	cin>>t;
	// t = 1;
	while(t--){
		int n;cin>>n;
		string a,b;cin>>a>>b;
		int num_a = binaryToDecimal(a);
		int num_b = binaryToDecimal(b);
		// int not_a = !num_a;
		// cout<<not_a;
		string inv_a;
	    // cout<<inv_a;
	    for(int i=0;i<a.size();i++){
	    	inv_a += (a[i]=='1')?'0':'1';
	    }
	    // cout<<inv_a;
		vector<int> ans;
		bool odd = true;
		string new_a(a);
		// cout<<new_a;
		while(1){
			odd = !odd;
			int temp = binaryToDecimal(new_a);
			num_b = binaryToDecimal(b);
			// cout<<new_a<<" "<<b<<endl;
 			int req_len = temp^num_b;
 			// cout<<req_len<<endl;
			if(req_len==0){
				break;
			}
			req_len =  (int)((log(req_len)/log(2)));
			if(req_len<0){
				break;
			}
			string temp_new_a,temp_new_b;

			for(int i=0;i<req_len;i++){
				temp_new_b += b[i];
			}
			b = temp_new_b;
			if(odd){
				for(int i=0;i<req_len;i++){
					temp_new_a+=a[i];
				}
			}
			else{
				for(int i=0;i<req_len;i++){
					temp_new_a += inv_a[i]; 
				}
			}
			new_a = temp_new_a;
			// cout<<new_a<<endl;
			// cout<<
			// cout<<req_len;
			// cout<<b<<endl;
			ans.push_back(req_len+1);
		}
		cout<<ans.size()<<" ";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}