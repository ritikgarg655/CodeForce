#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n, m;
long long x, k, y;
int a[N];
int b[N];

bool upd(int l, int r, long long &res) {
    if (l > r) return true;
    bool canDel = false;
    int mx = *max_element(a + l, a + r + 1);
    int len = r - l + 1;
    if (l - 1 >= 0 && a[l - 1] > mx) canDel = true;
    if (r + 1 < n && a[r + 1] > mx) canDel = true;
    if (len < k && !canDel) return false;
    
    int need = len % k;
    res += need * y;
    len -= need;
    
    if (y * k >= x) {
        res += len / k * x;
    } else if(canDel) {
        res += len * y;
    } else {
        res += (len - k) * y + x;
    }
    
    return true;
}

int main(){
    scanf("%d %d", &n, &m);
    scanf("%lld %lld %lld", &x, &k, &y);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    
    long long res = 0;
    int lst = -1, posa = 0, posb = 0;
    while (posb < m) {
        while(posa < n && a[posa] != b[posb]) ++posa;
        if (posa == n) {
            puts("-1");
            return 0;
        }
        
        if (!upd(lst + 1, posa - 1, res)) {
            puts("-1");
            return 0;
        }
        
        lst = posa;
        ++posb;
    }
    
    if (!upd(lst + 1, n - 1, res)) {
        puts("-1");
        return 0;
    }
    
    printf("%lld\n", res);
    
    return 0;
}