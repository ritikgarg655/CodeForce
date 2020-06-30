#include<bits/stdc++.h>
using namespace std;

// int max = 2*10000000+1;
int freq[10000001],count_prime_div[10000001],prefix_sum[10000001];
bool prime_num[10000001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;cin>>n;
	int arr[n];
	// int freq[2*10000000+1] = {0};
	// cout<<freq[5];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		freq[arr[i]]++;
	}
	// bool prime_num[2*10000000+1] = {false};
	prime_num[2] = true;
	prime_num[3] = true;
	for(int i=5;i<10000001;){
		prime_num[i] = true;
		prime_num[i+2] = true;
		i+=6;
	}
	for(int i = 2;i<10000001;i++){
		if(prime_num[i]){
			count_prime_div[i] = 0;
			for(int j=i;j<10000001;j+=i){
				count_prime_div[i] += freq[j];
			}
			// if(i<15)/
		}
	}
	// prefix_sum;
	prefix_sum[0] = 0;
	for(int i=1;i<10000001;i++){
		prefix_sum[i] = prefix_sum[i-1] + count_prime_div[i];
	}
	int m;cin>>m;int r,l;
	for(int i=0;i<m;i++){
	// for(int i=0;i<q;i++)
	// {
		cin>>l>>r;
		if(l>10000000)
		{
		    cout<<"0"<<"\n";
		    continue;
		}
		if(r>10000000)
		{
		    r=10000000;
		}
		cout<<prefix_sum[r]-prefix_sum[l-1]<<"\n";
	// }
	}
}
// #include<bits/stdc++.h>
// using namespace std;
// int a[10000001],b[10000001],c[10000001];
// int main()
// {
//     int n,x,q,l,r;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>x;
// 		a[x]++;
// 	}
// 	for(int i=2;i<10000001;i++)
// 	{
// 		if(c[i]==0)
// 		{
// 			if(a[i]!=0)
// 			{
// 				b[i]+=a[i];
// 			}
// 			for(int j=2*i;j<10000001;j+=i)
// 			{
// 				c[j]=1;
// 				b[i]+=a[j];
// 			}
// 		}
// 	}
// 	for(int i=1;i<10000001;i++)
// 	{
// 		b[i]+=b[i-1];
// 	}
// 	cin>>q;
// 	for(int i=0;i<q;i++)
// 	{
// 		cin>>l>>r;
// 		if(l>10000000)
// 		{
// 		    cout<<"0"<<"\n";
// 		    continue;
// 		}
// 		if(r>10000000)
// 		{
// 		    r=10000000;
// 		}
// 		cout<<b[r]-b[l-1]<<"\n";
// 	}
// }
// #include<bits/stdc++.h>
// using namespace std;
// int a[10000001],b[10000001],c[10000001];
// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// 	int n,x,q,l,r;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>x;
// 		a[x]++;
// 	}
// 	for(int i=2;i<10000001;i++)
// 	{
// 		if(c[i]==0)
// 		{
// 			if(a[i]!=0)
// 			{
// 				b[i]+=a[i];
// 			}
// 			for(int j=2*i;j<10000001;j+=i)
// 			{
// 				c[j]=1;
// 				b[i]+=a[j];
// 			}
// 		}
// 		if(i<15){
// 			cout<<b[i];
// 		}
// 	}
// 	for(int i=1;i<10000001;i++)
// 	{
// 		b[i]+=b[i-1];
// 	}
// 	cin>>q;
// 	for(int i=0;i<q;i++)
// 	{
// 		cin>>l>>r;
// 		if(l>10000000)
// 		{
// 		    cout<<"0"<<"\n";
// 		    continue;
// 		}
// 		if(r>10000000)
// 		{
// 		    r=10000000;
// 		}
// 		cout<<b[r]-b[l-1]<<"\n";
// 	}
// }