#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mod 1000000007
#define pi 3.1415926535897932384626
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ' : ' << x << endl;
#define deb2(x, y) cout << #x << ' : ' << x << ', ' << #y << ' : ' << y << endl;
 
void testcase() {
    int n;
    cin >> n;    
    string a(n, '9');
    int x = (n - 1) / 4;
    for(int i = n - x - 1; i < n; i++) a[i] = '8';
    cout << a;
}
 
signed main() {
#ifdef SP
freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;    
    for(int i = 0; i < t; i++) {
        // cout << "Case #" << i << ": ";
        testcase();
        cout << endl;
    }
}