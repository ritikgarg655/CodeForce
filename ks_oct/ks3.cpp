#include<bits/stdc++.h>
using namespace std;

// template 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vii;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,v) for(int i=0;i<v.size();i++)
#define reps(i,s) for(int i=0;i<s.length();i++)
#define allv(v) v.begin(),v.end()
#define alla(arr,sz) arr,arr+sz
#define rev(v) reverse(allv(v))
#define reva(a) reverse(alla(a))

// int minCost(int A[], int n,int k) 
// { 
//     int cost = 0; 
//   	sort(A, A + n); 
// 	 int K = A[n / 2]; 
//   	for (int i = 0; i < n; ++i) 
//         cost += abs(A[i] - K); 
//   	if (n % 2 == 0) { 
//         int tempCost = 0; 
//   	    K = A[(n / 2) - 1]; 
//   	    for (int i = 0; i < n; ++i) 
//             tempCost += min(min(abs(A[i] - K),abs(abs(k-K)+A[i])),abs(k-A[i])+K); 
//   	    cost = min(cost, tempCost);
//     } 
//   	return cost; 
// } 

int bs(int a[],int w,int n,int start,int end){
	if(end<start){
		return INT_MAX;
	}
	int tempCost1 = 0;
	int tempCost2 = 0;
	int tempCost3 = 0;
	int tempCost4 = INT_MAX;
	int tempCost5 = INT_MAX;
	int mid = (start+end)/2;
	for (int i = 0; i < w; ++i) 
        tempCost1 += min(min(abs(a[i] - start),abs(abs(n-start)+a[i])),abs(n-a[i])+start);
	for (int i = 0; i < w; ++i) 
        tempCost2 += min(min(abs(a[i] - end),abs(abs(n-end)+a[i])),abs(n-a[i])+end);
	for (int i = 0; i < w; ++i) 
        tempCost3 += min(min(abs(a[i] - mid),abs(abs(n-mid)+a[i])),abs(n-a[i])+mid); 
    if(start == end){
    	return tempCost1;
    }
    else if(abs(tempCost2- tempCost1)<=abs(tempCost2- tempCost3)){
    	tempCost4  = bs(a,w,n,start,mid-1);
    }
    else{
    	tempCost5 = bs(a,w,n,mid+1,end);
    }
    return min(tempCost1,min(tempCost2,min(tempCost3,min(tempCost4,tempCost5))));
}

void solve(int in){
	int n,w;
	cin>>w>>n;
	int arr[w];
	int sum = 0;
	int sum1 = 0;
	int s[w];
	for(int i=0;i<w;i++){
		cin>>arr[i];
		s[i] = n-arr[i];
		if(arr[i] <n/2){
			sum += arr[i];
			sum1 += arr[i]-1;
		}
		else{
			sum += (n-arr[i]);
			sum1 += (n-arr[i])+1;
		}
	}
	cout<<"Case #"<<in<<": "<<min(sum,min(sum1,bs(arr,w,n,1,n)))<<endl;
}

	int main(){
		ios::sync_with_stdio(0);
	    cin.tie(0);
	    cout.tie(0);
		int t;
		// t = 1;
		cin>>t;
		for(int i=1;i<=t;i++){
			solve(i);
		}
		
	}