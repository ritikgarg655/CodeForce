#include<bits/stdc++.h>
using namespace std;

 
int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
}
int solve(vector<int> &A, int B, int C) {
    long long int small = 0,len_c = 0;
    bool num[10] = {false};
    int temp_c = C;
    while(temp_c>0){
        temp_c = temp_c /10;
        // cout<<len_c;
        len_c++;
    }
    // cout<<len_c;
    int freq[10] = {0};
    // cout<<freq[9]<<endl;
    for(int i=0;i<A.size();i++){
    	// cout<<A[i];
        freq[A[i]]++;
        // cout<<freq[A[i]];
    }
    // cout<<freq[9];
    int ans = 0;
    if(B>len_c){
        return 0;
    }
    else if(B == len_c){
        int prev_num = 0;
        for(int i=1;i<=B;i++){
            bool num[10] = {false};
            int count = 0;
            prev_num *=10;
            int digit = (C/pow(10,len_c-i) - prev_num);
            prev_num = prev_num*10 + digit		;
            cout<<digit;
            for(int j=0;j<digit;j++){
            	// cout<<freq[j]<<" " ;
                if(j==0 and i==1 and B>1 ){
                    continue;
                }
                if(freq[j]>0){
                    // cout<<j<<endl;
                    count ++;
                    freq[j]--;
                    ans += (factorial((A.size() - i))/factorial(A.size()- i -(B-i))) ;
                    for(int k=0;k<10;k++){
                        ans /= factorial(freq[k]);
                    }
                    freq[j]++;
                }
            }
            freq[digit]--;
            cout<<i<<ans;
        }
    }
    else{
        len_c = B;
        C=0;
        for(int i=0;i<B;i++){
            C = 9 + (C*10);
        }
        // cout<<C;
        int prev_num = 0;
        for(int i=1;i<=B;i++){
            bool num[10] = {false};
            int count = 0;
            prev_num *=10;
            int digit = (C/pow(10,len_c-i) - prev_num);
            prev_num = prev_num*10 + digit		;
            // cout<<digit;
            for(int j=0;j<10;j++){
                if(j==0 and i==1 and B>1 ){
                    continue;
                }
                if(freq[j]>0){
                    // cout<<j<<endl;
                    count ++;
                    freq[j]--;
                    ans += (factorial((A.size() - 1))/factorial(A.size()- 1 -(B-i))) ;
                    for(int k=0;k<10;k++){
                        ans /= factorial(freq[k]);
                    }
                    freq[j]++;
                }
            }
            freq[digit]--;
        }
        
    }
    return ans;
}

int main(){
	vector<int> v{0, 1, 2, 5 };
	cout<<solve(v,2,40);
}