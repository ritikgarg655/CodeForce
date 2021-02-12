#include <bits/stdc++.h>
using namespace std;
 
#define dbg(v) cout << __LINE__ << ": " << #v << " = " << v << endl
 
const int N = 4e2 + 5;
const int INF = 1e5;
 
int n;
int a[N];
int dp[N][N], vis[N][N], p = 1;
 
int solve (int i, int prv) {
    if (i == n) {
        return 0;
    }
    if (prv > N) {
        return INF;
    }
    if (vis[i][prv] == p) {
        return dp[i][prv];
    }
    vis[i][prv] = p;
    return dp[i][prv] = min(solve(i, prv + 1), abs(prv - a[i]) + solve(i + 1, prv + 1));
}
 
int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 0; cs < T; cs++, ++p) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("%d\n", solve(0, 1));
    }
    return 0;
}
 