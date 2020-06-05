// #include<bits/stdc++.h>
// using namespace std;
  
// int invertBits(int num) 
// { 
//     // calculating number of bits 
//     // in the number 
//     int x = log2(num) + 1; 
  
//     // Inverting the bits one by one 
//     for (int i = 0; i < x; i++)  
//        num = (num ^ (1 << i));  
   
//     return num; 
// } 
// int main(){
// 	int t;cin>>t;while(t--){
// 		int n;cin>>n;
// 		int arr[n];
// 		int sum = -1;
// 		int maxt = 0;
// 		bool visited[1025] = {false};
// 		int xor_t = 0;
// 		long long int sum_Arr = 0,sum_Arr_neg = 0;
// 		for(int i=0;i<n;i++){
// 			// int a;
// 			cin>>arr[i];
// 			visited[arr[i]] = true;
// 			if(arr[i]>maxt){
// 				maxt = arr[i];
// 			}
// 			if(i==0){
// 				xor_t = arr[0];
// 			}
// 			else{
// 				xor_t = xor_t^arr[i];
// 			}
// 			sum_Arr+=arr[i];
// 			sum_Arr_neg = sum_Arr_neg + invertBits(arr[i]);
// 		}
// 		for(int i =0 ;i<n;i++){
// 			sum_Arr_neg = sum_Arr_neg + invertBits(arr[i]+pow(2,ceil(log2(maxt))));

// 		}
// 		int start =1;
// 		cout<<sum_Arr<<sum_Arr_neg<<endl;
// 		while(start<=pow(2,ceil(log2(maxt)))){
// 			// int i;
// 			// for(i=0;i<n;i++){
// 			// 	if(!visited[start^arr[i]]){
// 			// 		break;
// 			// 	}
// 			// }
// 			// if(i==n){
// 			// 	sum = start;
// 			// 	break;
// 			// }
// 			int a = invertBits(start +pow(2,ceil(log2(maxt))));
// 			// cout<<a<<endl;
// 			if((sum_Arr & a) + (sum_Arr_neg & start) == sum_Arr){
// 				sum = start;
// 				break;
// 			}
// 			start++;
// 		}
// 		// if(sum>max or sum<=0){
// 		// 	sum = -1;
// 		// }
// 		cout<<sum<<endl;
// 	}
// }
    #include<bits/stdc++.h>
    using namespace std;
     
    int main(){
    	int t;cin>>t;while(t--){
    		int n;cin>>n;
    		int arr[n];
    		int sum = -1;
    		int max = 0;
    		bool visited[1025] = {false};
    		for(int i=0;i<n;i++){
    			// int a;
    			cin>>arr[i];
    			visited[arr[i]] = true;
    			if(arr[i]>max){
    				max = arr[i];
    			}
    		}
    		int start = 1;
    		while(start<=pow(2,log2(max)+1)){
    			int i;
    			for(i=0;i<n;i++){
    				if(start^arr[i]<1025){
	    				if(!visited[start^arr[i]]){
	    					break;
	    				}
	    			}
    			}
    			if(i==n){
    				sum = start;
    				break;
    			}
    			start++;
    		}
    		// if(sum>max or sum<=0){
    		// 	sum = -1;
    		// }
    		cout<<sum<<endl;
    	}
    }