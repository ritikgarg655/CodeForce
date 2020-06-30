#include <bits\stdc++.h>
 
using namespace std;
 
const int M = 1e5+10;
int a[M] , dp[M];
 
int main()
{
	int n , max = 0;
	cin >> n;
	for (int i = 0; i < n ; i++)
		cin >> a[i];
	for (int i = 0 ; i < M ; i++)
		dp[i] = M;
	for (int i = 0 ; i < n ; i++)
	{
		dp[lower_bound(dp , dp+M , a[i]) - dp] = a[i];
	}
	for (int i = 0 ; i <= n ; i++)
	{
		if (dp[i] == M)
		{
			max = i;
			break;
		}
	}
	cout << max << endl;
}