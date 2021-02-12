#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int lr = 0;
    int beg = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            --lr;
        } else {
            ++lr;
        }
        if (beg == -1 && lr < 0) {
            beg = i;
        } 
        else if (beg >= 0 && lr == 0) {
            ans += i - beg + 1;
            beg = -1;
        }
    }
    if (lr != 0) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    /* int T; */
    /* cin >> T; */
    /* for (int t = 0; t < T; ++t) { */
        solve();
    /* } */
    return 0;
}