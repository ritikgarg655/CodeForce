// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	int n;cin>>n;
// 	int arr[n][n];
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cin>>arr[i][j];
// 		}
// 	}
// 	int row_sum[2*n] = {0};
// 	for(int i=0;i<n;i++){
// 		for(int j=0,k=i;j<n and k<n;j++,k++){
// 			row_sum[i] += arr[k][j]; 
// 		}
// 		// cout<<row_sum[i]<<endl;
// 	}
// 	for(int i=1;i<n;i++){
// 		for(int j=0,k=i;k<n and j<n;j++,k++){
// 			row_sum[i+n-1] += arr[j][k];
// 		}
// 		// cout<<row_sum[i+n-1]<<endl;
// 	}
// 	int col_sum[2*n] = {0};
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<=i;j++){
// 			col_sum[i] += arr[j][i-j]; 
// 		}
// 		// cout<<col_sum[i]<<endl;
// 	}
// 	for(int i=1;i<n;i++){
// 		for(int j=n-1;j>=i;j--){
// 			col_sum[i+n-1] += arr[n+i-1-j][j];
// 		}
// 		// cout<<col_sum[i+n-1]<<endl;
// 	}
// 	int row_first_index = 0;
// 	int row_sec_index = 0;
// 	int col_first_index = 0;
// 	int col_sec_index = 0;
// 	int max = 0;
// 	for(int i=0;i<2*n;i++){
// 		if(max<row_sum[i]){
// 			max = row_sum[i];
// 			row_first_index = i;
// 		}
// 	}
// 	// for(int i=0;i<n;i++){
// 	// 	for(int j=0;j<n;j++){

// 	// 	}
// 	// }
// }
    #include <iostream>
    #include <cstdio>
     
    using namespace std;
    const int NMAX = 2014;
    long long d1[2*NMAX], d2[2*NMAX], sol[2];
    pair < int , int > v[2];
    int a[NMAX][NMAX];
    inline void Update(const int c,const int i,const int j,const long long val){
        if(val > sol[c]){
            sol[c] = val;
            v[c].first = i;
            v[c].second = j;
        }
    }
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("date.in","r",stdin);
            freopen("date.out","w",stdout);
        #endif
        cin.sync_with_stdio(false);
        int n;
        cin >> n;
        sol[0] = sol[1] = -1; 
        for(int i = 1;i <= n; ++i)
            for(int j = 1;j <= n; ++j){
                int x;
                cin >> a[i][j];
                d1[i+j] += a[i][j];
                d2[i-j+n] += a[i][j];
            }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                Update((i+j)&1,i,j,d1[i+j]+d2[i-j+n]-a[i][j]);
        cout<<sol[0]+sol[1]<<"\n";
        if(v[0] > v[1])
            swap(v[0],v[1]);
        cout<<v[0].first<<" "<<v[0].second<<" ";
        cout<<v[1].first<<" "<<v[1].second<<"\n";
        return 0;
    }